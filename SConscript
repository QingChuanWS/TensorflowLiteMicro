from building import *

cwd     = GetCurrentDir()
src     = Glob('*.c')
CPPPATH = [cwd]

group = DefineGroup('Hello', src, depend = [''], CPPPATH = CPPPATH)

Return('group')
