env = Environment(
	CCFLAGS = ['-Wall', '-g'],
)

sources = [
	'CFileSpectrum.cpp',
	'CFileHC.cpp',
	'CFileCPM.cpp',
	'CFile.cpp',
]

env.Program('bin/hcdisk2', [
	'nop.cpp',
] + sources)
