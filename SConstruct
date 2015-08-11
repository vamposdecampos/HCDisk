env = Environment(
	CCFLAGS = ['-Wall', '-g'],
)

sources = [
	'CFileSpectrum.cpp',
]

env.Program('bin/hcdisk2', [
	'nop.cpp',
] + sources)
