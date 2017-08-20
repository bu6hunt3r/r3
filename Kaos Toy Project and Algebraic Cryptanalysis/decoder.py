#!/usr/bin/env python

class Val(object):
    def __init__(self, val = UNDEF, exp = None):
        self.val=val
        self.exp=exp

    def __str__(self):
        return str(self.exp) if self.is_symbolic() else hex(self.val)

    def is_symbolic(self):
        return self.val is None

    def is_concrete(self):
        return not self.is_symbolic()

    def to_z3(self, state, size):
        #
        # generate Z3 expression that represents this value
        #

        def _z3_size(size):
            return { U1: 1, U8: 8, U16: 16, U32: 32, U64: 64 }[ size ]

        def _z3_exp(exp, size):
    
            if isinstance(exp, SymVal):

                if state.has_key(exp.name):

                    return state[exp.name]

                else:

                    return z3.BitVec(exp.name, _z3_size(exp.size))                                 

            elif isinstance(exp, SymConst):

                return z3.BitVecVal(exp.val, _z3_size(exp.size))                

            elif isinstance(exp, SymExp):

                a, b = exp.a, exp.b

                assert isinstance(a, SymVal) or isinstance(a, SymConst)
                assert b is None or isinstance(b, SymVal) or isinstance(b, SymConst)
                assert b is None or a.size == b.size                

                a = a if a is None else _z3_exp(a, a.size)
                b = b if b is None else _z3_exp(b, b.size)                     

                # makes 1 bit bitvectors from booleans
                _z3_bool_to_bv = lambda exp: z3.If(exp, z3.BitVecVal(1, 1), z3.BitVecVal(0, 1))

                # z3 expression from SymExp
                ret = { I_ADD: lambda: a + b,
                        I_SUB: lambda: a - b,            
                        I_NEG: lambda: -a,
                        I_MUL: lambda: a * b,
                        I_DIV: lambda: z3.UDiv(a, b),
                        I_MOD: lambda: z3.URem(a, b),
                        I_SHR: lambda: z3.LShR(a, b),
                        I_SHL: lambda: a << b,                     
                         I_OR: lambda: a | b,
                        I_AND: lambda: a & b,
                        I_XOR: lambda: a ^ b,
                        I_NOT: lambda: ~a,
                         I_EQ: lambda: _z3_bool_to_bv(a == b),
                         I_LT: lambda: _z3_bool_to_bv(z3.ULT(a, b)) }[exp.op]()

                size_src = _z3_size(exp.a.size)
                size_dst = _z3_size(size)

                if size_src > size_dst:

                    # convert to smaller value
                    return z3.Extract(size_dst - 1, 0, ret)

                elif size_src < size_dst:

                    # convert to bigger value
                    return z3.Concat(z3.BitVecVal(0, size_dst - size_src), ret)

                else:

                    return ret

            else:

                assert False    

        if self.is_concrete():

            # use concrete value
            return z3.BitVecVal(self.val, _z3_size(size))

        else:

            # build Z3 expression
            return _z3_exp(self.exp, size)


class Reg(VM.Reg):

    def to_symbolic(self):

        # get symbolic representation of register contents
        if self.val.is_concrete():

            # use concrete value
            return SymConst(self.get_val(), self.size)

        else:

            if self.regs_map.has_key(self.name):

                return SymVal(self.regs_map[self.name], self.size)

            # use symbolic value
            return SymVal(self.name, self.size) if self.val.exp is None \
                                                else self.val.exp    

    def get_val(self):

        # get concrete value of the register if it's available
        assert self.val.is_concrete()
        
        return super(Reg, self).get_val(self.val.val)

    def str_val(self):

        return str(self.val.exp) if self.val.is_symbolic() \
                                 else super(Reg, self).str_val(self.val.val)

