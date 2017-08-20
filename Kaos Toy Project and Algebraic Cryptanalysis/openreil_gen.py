from pyopenreil.REIL import *
from pyopenreil.symbolic import *
from pyopenreil.VM import *

from pyopenreil.utils import bin_PE

# VA's of required functions and variables
check_serial = 0x004010EC        
installation_ID = 0x004093A8        

# create translator instance
tr = CodeStorageTranslator(bin_PE.Reader('toyproject.exe'))

# construct data flow graph of check_serial() function
dfg = DFGraphBuilder(tr).traverse(check_serial)

# Run all available code optimizations and update 
# storage with new function code.
dfg.optimize_all(tr.storage)

# print generated IR code
print tr.get_func(check_serial)
