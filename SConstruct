env = Environment(
	CCFLAGS = ['-Wall', '-g'],
)

sources = [
	'CFileSpectrum.cpp',
	'CFileHC.cpp',
	'CFileCPM.cpp',
	'CFile.cpp',
	'CFileTRD.cpp',
	'CFilePlus3.cpp',
	'CFileSystem.cpp',
	'CFileArchive.cpp',
	'CFileArchiveTape.cpp',
	'DiskBase.cpp',
	'DiskImgRaw.cpp',
	'DiskImgCQM.cpp',
	'edsk.cpp',
	'dsk.cpp',
	'CFSOpus.cpp',
	'CFSCPMHC.cpp',
	'CFSCPM.cpp',
	'CFSTRDSCL.cpp',
	'CFSCPMPlus3.cpp',
	'CFSCobraDEVIL.cpp',
	'CFSMGT.cpp',
	'CFSTRD.cpp',

	'Tape/tap.cpp',
	'Tape/TapeBlock.cpp',
	'Tape/TZX.cpp',
]

env.Program('bin/hcdisk2', [
	'nop.cpp',
] + sources)
