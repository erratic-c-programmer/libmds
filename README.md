# libmds
Library for misc. data structures

## Features:
- Written in pure C
- Has data structures:
    - vector
    - llist
    - string
- Allocates lots of stuff on heap, so is 2x slower than C++ STL :-(
- But is quite a lot more memory-efficient!

## Compiling
### Prerequisites:
- gcc/clang
- GNU make
- sphinx\*
- sphinx_rtd_theme/sphinx-rtd-theme\*
- doxygen\*

\* Required for documentation

To build static and dynamic libraries with documentation:
```linux
$ make
```
To build without documentation:
```linux
$ (cd src/; make)
```
