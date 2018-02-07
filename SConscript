from building import *

cwd     = GetCurrentDir()
src     = Glob('*.c') + Glob('*.cpp')
CPPPATH = [cwd]

group = DefineGroup('Hello', src, depend = ['PKG_USING_HELLO'], CPPPATH = CPPPATH)

Return('group')
