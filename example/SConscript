from building import *

cwd     = GetCurrentDir()
src     = Glob('*.c') + Glob('*.cpp')
CPPPATH = [cwd]

group = DefineGroup('Hello', src, depend = ['HELLO_USING_EXAMPLE'], CPPPATH = CPPPATH)

Return('group')
