#import mydlls
#mydlls.print_hello()

import importlib

funcs = importlib.import_module('mydll')

funcs.print_hello()