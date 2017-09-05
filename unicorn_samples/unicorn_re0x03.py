from __future__ import print_function
from unicorn import *
from unicorn.x86_const import *
from keystone import *
import struct
from keystone import *


def array_to_code(arr):
    b=b""
    for ins in arr:
        b+=struct.pack("B",ins)
    
    return b

code=b"\xc7\x45\xe3\x51\x7d\x7c\x75\xc7\x45\xe7\x60\x73\x66\x67\xc7\x45\xeb\x7e\x73\x66\x7b\xc7\x45\xef\x7d\x7c\x61\x33\xc6\x45\xf3\x00"
code+=b"\x8d\x55\xe3\x8b\x45\xd8\x01\xd0\x0f\xb6\x00\x89\xc2\x8b\x45\x08\x31\xd0\x8d\x4d\xe3\x8b\x55\xd8\x01\xca\x88\x02\x83\x45\xd8\x01\x8b\x45\xd8"

ADDRESS=0x100000
STACK_ADDRESS=ADDRESS + 0x1000

print("Emulating x64 code")
try:
    emu=Uc(UC_ARCH_X86,UC_MODE_32)
    emu.mem_map(ADDRESS,2*1024*1024)
    emu.mem_write(ADDRESS, code)
    emu.reg_write(UC_X86_REG_EBP,STACK_ADDRESS)




    #emu.mem_write(STACK_ADDRESS-0x10,b"\xef\xbe\xad\xde")
    emu.emu_start(ADDRESS,ADDRESS+len(code))
    eax=emu.reg_read(UC_X86_REG_EAX)
    edx=emu.reg_read(UC_X86_REG_EDX)
    operand=emu.mem_read(STACK_ADDRESS-0x24,4)
    #ebp=emu.mem_read(STACK_ADDRESS-0x10,4)
    #print(type(eax))
    print("EAX = ", repr(eax))
    print("EDX ", repr(edx))
    print("Operand is: ", repr(operand))

    #print(struct.pack("L",eax))
except UcError as e:
    print("ERROR: %s" % e)

