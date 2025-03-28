HCDisk 2.0 - PC disk utility for Sinclair Spectrum related file systems.
George Chirtoaca, June 2014, george_chirtoaca@yahoo.com

1. What is it?
2. What can it do?
3. What are the usage scenarios?
4. Where does the name come from?
5. What commands are available?
6. What about the source code?
7. What features are planned?


1. What is it?

	HCDisk is a tool able to transfer files to and from several file systems Specific to the Sinclair Spectrum computer and clones. 

2. What can it do?

	It can understand these file systems:
- CPM - Spectrum +3 and various clones (HC, CoBra)
- +3 BASIC (CPM based)
- Betadisk TR-DOS
- Miles Gordon Technologies +D
- Opus Discovery
- ICE Felix HC BASIC (Romanian clone, CPM based)
- ICTI CoBra Devil FS (Romanian clone)
- Electronica CIP-04 (Spectrum +3 clone from Romania, with 3.5 disk drive)
File systems based on CPM are read-write, the others are read only (for now).

	Several disk image types are supported:
- Physical disks inserted into the PC floppy drive
- RAW, including TRD, MGT, OPD
- DSK/EDSK - CPCEMU
- CQM (read only) - Copy QM by Sydex
- SCL (read only) - Russian emulators
- TD0 - Teledisk by Sydex
- Tape images: TAP, TZX
	
	Note: For accessing floppy disks in physical drive for all supported formats, you need Simon Owen's fdrawcmd driver: http://simonowen.com/fdrawcmd/ .
	For standard geometries supported by Windows, the standard Windows driver is now used (added in January 2022). This also works with USB floppy drives for modern computers without a floppy controller.
	The geometries supported by Windows are using sector size of 512 bytes and also 40 and 80 tracks, with 8, 9, 15 and 18 sectors per track, single or dual sided. The USB floppy drives only support 80x2x9 DD and 80x2x18 HD TxHxS.
	

	It also includes file conversion for Spectrum Specific files, to be viewed on PC:
- converts Spectrum BASIC programs to BASIC source code 
- converts Spectrum SCREEN$ files to animated GIFs
- includes a disassembler for CODE files
- includes a hex viewer
	
3. What are the usage scenarios?

- browse and view files from physical disks, disk images or tape images; an extended
file catalog is displayed (read text documents from CPM disks, browse your old BASIC programs, etc)
- transfer physical disks into disk images for preservation or use on emulators
- export and import files between different file systems
(Spectrum +3 to MGT +D, Opus to Tape, etc)
- disk to tape and tape to disk conversion
- tape image to sound signal conversion or WAV file (for use on a Spectrum without disk)
- disk image conversion between formats (RAW to DSK, CQM to RAW, etc)
- create physical disks from downloaded disk images, to be used on the real machine

4. Where does the name come from?

	HC is the name of a Sinclair Spectrum compatible computer series manufactured in Romania by the I.C.E. Felix plant. 
I had one as my first computer.
	The first version of HCDisk only understood the file system specific to HC, but I kept the name, even if now it can 
process file systems for several other clones and add-ons. Not by coincidence, HC is also an acronym for Home Computer.
So this tool applies to home computers.

5. What commands are available?

help ?  - Command list, this message

fsinfo  - Display the known file systems

Displays the known file systems, with details, from the program help (geometry, block size, block count, directory capacity, 
boot track count):
Name                    |Geometry       |Bl.Sz. |Bl.Cnt |Dir.   |Boot
--------------------------------------------------------------------
HC BASIC 5.25"          |40x2x16x256    |2048   |160    |128    |0
HC BASIC 3.5"           |80x2x16x256    |2048   |320    |128    |0
CP/M 2.2 5.25"          |40x2x9x512     |2048   |175    |64     |2
CP/M 2.2 3.5"           |80x2x9x512     |2048   |351    |128    |4
Spectrum +3 PCW         |40x2x9x512     |2048   |175    |64     |1
Spectrum +3 CP/M SSDD   |40x1x9x512     |1024   |175    |64     |1
Spectrum +3 CP/M DSDD   |80x2x9x512     |2048   |357    |256    |1
Spectrum +3 HiForm 203  |42x1x10x512    |1024   |205    |64     |1
Electronica CIP-04      |80x1x9x512     |1024   |355    |64     |1
TRDOS DS 3.5"           |80x2x16x256    |256    |2544   |128    |1
TRDOS DS 5.25"          |40x2x16x256    |256    |1264   |128    |1
TRDOS SS 3.5"           |80x1x16x256    |256    |1264   |128    |1
TRDOS SS 5.25"          |40x1x16x256    |256    |624    |128    |1
CoBra Devil             |80x2x18x256    |9216   |77     |108    |0
Opus Discovery          |40x1x18x256    |256    |720    |112    |0
MGT +D                  |80x2x10x512    |512    |3125   |80     |0

stat  - Display the current file system parameters: (total/free blocks, total/free space, disk geometry, disk type, etc)
	Example for HC BASIC:
Storage: RAW, File system: HC BASIC 3.5"
Disk geometry: Tracks: 80, Sides: 2, Sectors: 16, Sector Size: 256
Block size: 2.00 K, Blocks free/max: 10/320, Space free/max KB: 20/640
Directory entries free/max: 44/128
File system features: Sinclair Spectrum, File attributes, File folders, Case sensitive names

open  - Open disk or disk image
- <drive|image>: The disk/image to open
- [-t] x: The number of file system type to use - optionaly, auto select the type from the list
	The program tries to auto detect the file system based on disk geometry. If several matches are found,
a list is displayed for the user to pick one. TRDos is the only file system that has a signature that can be check,
otherwise there's no easy way to detect if the selection is valid, and errors can occur, like strange, unreadable file names.

close  - Close disk or disk image

ls dir  - List directory
- [<folder><\>file spec.]: filespec: *.com or 1\*, etc - folder for CPM can be specified with back slash
- [-sn|-ss|-st]: Sort by name|size|type
- [-ne]: Don't show extended info, faster - doesn't access the file header, and it's faster for physical disks
- [-del]: Include deleted files in listing. 

	Example of Spectrum +3 disk catalog. Other file systems for Spectrum look similar. Information displayed is:
file index, file folder (for CPM), file name and extension, file size on disk, file attributes (if available for the file system). 
For BASIC file systems, there's also specific info displayed: file type, code start address/program start line, and lenght.

IDX     Folder  Name            Size(KB)        Attr    Type    Start   BasLen
------------------------------------------------------------------------------
  1     0       8PAT1           15.00           ---     Program  2700   15025
  2     0       BURROW1          9.00           ---     Program     1    8590
  3     0       RUFUS            1.00           ---     Program    10     211
  4     0       RUFUS   .1       5.00           ---     Bytes   50000    4152
  5     0       CASH1           11.00           ---     Program     1   10119
  6     0       CHIRP1           7.00           ---     Program     1    6513
  7     0       CRASH1           3.00           ---     Program    10    2120
  8     0       CRASH2           2.00           ---     Bytes   27970    1470
  9     0       CRASH3           3.00           ---     Bytes   30697    2025
 10     0       RUFUS   .2      26.00           ---     Bytes   38540   25875
 11     0       DISK             2.00           ---     Program    10    1024
 12     0       KRIEG1           4.00           ---     Program     1    3525
 13     0       LETHOS1          1.00           ---     Program     0     154
 14     0       LETHOS2          7.00           ---     Bytes   16384    6912
 15     0       LETHOS3         41.00           ---     Program     0   40970
 16     0       ORION1          38.00           ---     Program     0   38325
 17     0       OXO1             9.00           ---     Program     1    8311
Space free/filled/total : 019/186/205 KB

get  - Copy file(s) to PC
- <["]filespec["]>: * or *.com or readme.txt, "1 2", etc - names with spaces are supported, but must be enclosed in quotes
- [-t]: Copy as text - only display printable chars, usefull for Tasword files

type cat  - Display file
- <file spec.>: * or *.com or readme.txt, etc
- [-h]: display as hex
	BASIC programs are decoded into source code. Numeric values are displayed, but only if are different from the textual representations. 
Also, embedded attributes are displayed (as text). The program variables values are displayed, if saved with the 
program, as it is the case when saving a program after being run, without first CLEARing the memory.
	SCREEN$ files are displayed as animated GIF files.
	Code files are disassembled.
	Any file can also be displayed as hexadecimal.

copydisk  - Copy current disk to another disk or image
- <destination>: destination disk/image - if writing to physical a disk, that disk must be properly formatted

put  - Copy PC file to file system
- <source file>: the file to copy
- [-n newname]: name for destination file
- [-d <destination folder>]: file folder - for CPM
- [-s start, -t p|b|c|n file type]: Spectrum file attributes; type is [p]rogram, [b]ytes, [c]har arr., [n]umber arr.

del rm  - Delete file(s)
- <file spec.>: the file(s) to delete, ex: del *.com; A confirmation is displayed.

ren  - Rename file
- <file name>: the file to rename
- <new name>: new file name

!  - Execute DOS command after '!' -  will execut the shell command. Note the space after !.
- <DOS command>: ! dir, ! mkdir, etc

tapplay  - Play the tape as sound asynchronously
- [-w]: play to a .wav file instead of real-time
	You can connect the PC audio output to a Spectrum tape input, and load the tape image.
Copy protected programs, like Speedlock are supported, in TZX images.

Example of async. tape playing:
Playing the tape. Press ESC to quit, SPACE to pause. Block count is: 80.
00:     Std. Block      Program: run            19      00
01:     Std. Block      Data   :                1288    FF
Progress: 77 %

tapexp  - Exports the files to a tape image
- <.tap name>: the TAP file name
- [file mask]: the file name mask - if specified, only these files will be exported, not all the files.

tapimp  - Imports the TAP file to disk
- <.tap name>: the TAP file name
- [file mask]: the file name mask - if specified, only these files will be exported, not all the files.

formatdisk - Format a physical disk or a disk image for a certain file system
- <disk/image> : the disk drive or image to format
- [-t] : the file system format number to use, as found in fsinfo command

exit quit  - Exit program

	Commands can be concatenated using the ":" character. Example: "open -t 1 : ls : close" .
	The same commands can be entered interactively, or on the program command line, making it easier to use it in batch programs:
"hcdisk2.exe open plus3.dsk -t 1 : cat run : exit >> run.bas" - will open the disk plus3.dsk, specifying the type of file system
to be preselected, as the first in the list (1), display the basic program named "run", and then exit. 
Because the output is redirected into the file run.bas, the result is the BASIC program into a text file.
	
6. What about the source code?

	The program is written in C++, and it's using the Standard Template Library (STL). I used Visual Studio 2008 for development,
but I made sure a free compiler can also be used, and I tested with Borland C++ 5.5 free compiler, that can be downloaded from here:
http://edn.embarcadero.com/article/20633 .
	Most of the code is written by me, from scratch, but some components are used, as follows:
- SCREEN$ to GIF code is written by M. van der Heide; I had my own implementation, with the added functionality of saving to 
other formats besides GIF, but it used the GDI+ library, which is harder to use with the Borland compiler.
- The disassembler is dz80, Copyright 1996-2002 Mark Incley
- The CQM image driver is based on LIBDSK 1.2.1, Copyright (C) 2001-2,2005  John Elliott <jce@seasip.demon.co.uk>
	
	The program is designed with Object Oriented Design in mind. The disk object is decoupled from the file system object,
so that any combination can be used, CPM in DSK image, TRDOS in CQM image, MGT +D on physical disks, etc. The file system is 
abstracted as a collection of allocation blocks, and a file catalog. The file system has attribute flags, to be able to determine
at runtime what features it support: file attributes, disk label, Spectrum specific files, etc. A file object contains a list of file system blocks 
that it occupies, a list of catalog entries that is occupies, a file name, attributes, length. The file system object is a factory for file objects. 
Files can be raw files, or Sinclair Spectrum specific files. The base class for file system is file archive, used for file collections that are not 
disks, like the tape images, SCL images, or in the future, file archive (ZIP, etc).
	The code is not as clean as I would like. It is gathered from parts I wrote across several years.
	The license is GPL, which in my understanding, means that you can use it in your own programs, as long as you specify 
the original author and include the changes you added to the code, when you release your code.

7. What other features are planned?
- Add support for serial transfer using the PC COM port and IF1 compatible Spectrum interfaces
- Add support for the FAT file system
- Add file system configuration in external config. file, to be able to add varations of a file system without recompiling
- Add write support for the current read-only file systems