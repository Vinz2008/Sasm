# SASM

## What is SASM

SASM means Simple ASseMbly.
Sasm is an assembly-like programming language. It is compiled to x86_64 intel assembly.  
It uses simpler and easier to remember instructions

### What is in this repo ?
There are a compiler from SASM to Intel x86 Linux 32 bit assembly written in C.


## Installation

### Windows installer
Launch the Windows installer from the release  
It will automatically install sasm and add it to the PATH with [PathEd](https://github.com/awaescher/PathEd)
## Building from Source

### Linux, Macos and other Unix/BSD
launch ```make``` then ```make install```
### Windows
install [MinGw](https://sourceforge.net/projects/mingw/) (I strongly advise you to create a copy of ming32-make.exe named make.exe so it is the same command for windows and other platforms. If you don't, you need to replace make by ming32-make in the following command)

launch  ```` make ```` then create an installer with the nsis script in the [nsis app](https://nsis.sourceforge.io/Download)
