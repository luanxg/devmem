
from building import *
import rtconfig

cwd     = GetCurrentDir()
src     = Glob('*.c')
CPPPATH = []

group = DefineGroup('devmem', src, depend = ['PKG_USING_DEVMEM'], CPPPATH = CPPPATH)

Return('group')
