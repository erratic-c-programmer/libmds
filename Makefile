WARNINGS += -Wpedantic
WARNINGS += -Wall
WARNINGS += -Wextra
WARNINGS += -Waggregate-return
WARNINGS += -Wbad-function-cast
WARNINGS += -Wcast-align
WARNINGS += -Wcast-qual
WARNINGS += -Wdeclaration-after-statement
WARNINGS += -Wfloat-equal
WARNINGS += -Wformat=2
WARNINGS += -Wmissing-declarations
WARNINGS += -Wmissing-include-dirs
WARNINGS += -Wmissing-prototypes
WARNINGS += -Wnested-externs
WARNINGS += -Wpointer-arith
WARNINGS += -Wredundant-decls
WARNINGS += -Wsequence-point
WARNINGS += -Wshadow
WARNINGS += -Wstrict-prototypes
WARNINGS += -Wswitch
WARNINGS += -Wundef
WARNINGS += -Wunreachable-code
WARNINGS += -Wunused-parameter
WARNINGS += -Wwrite-strings
WARNINGS += -Werror

DEBUG = -g
OPTIM = -O3 -march=native -mtune=native
CFLAGS= $(WARNINGS) $(DEBUG) $(OPTIM) -std=c99 -fPIC -o $@
CC=gcc
OCC=$(CC) -c
AR=ar
V=@

.PHONY : all static dynamic test

all : static dynamic test

static : libmds.a

dynamic : libmds.so

libmds.a : dynstr/strop.o llist/llist.o vector/vector.o
	$V printf "Creating static library \033[1m$@\033[0m...\n"
	$V $(AR) rcs $@ $^


libmds.so : dynstr/strop.o llist/llist.o vector/vector.o
	$V printf "Creating shared library \033[1m$@\033[0m...\n"
	$V $(CC) $(CFLAGS) -shared $^

%.o : %.c
	$V $(OCC) $(CFLAGS) $^
	$V printf "Compiling \033[1m$@\033[0m from $^...\n"

###############################################################################

test : tests/hello tests/llist tests/llist_huge tests/vector tests/vector_huge

tests/hello : tests/hello.c libmds.a
	$V $(CC) $(CFLAGS) $^
	$V printf "Compiling and linking \033[1m$@\033[0m...\n"

tests/llist : tests/llist.c libmds.a
	$V $(CC) $(CFLAGS) $^
	$V printf "Compiling and linking \033[1m$@\033[0m...\n"

tests/llist_huge : tests/llist_huge.c libmds.a
	$V $(CC) $(CFLAGS) $^
	$V printf "Compiling and linking \033[1m$@\033[0m...\n"

tests/vector : tests/vector.c libmds.a
	$V $(CC) $(CFLAGS) $^
	$V printf "Compiling and linking \033[1m$@\033[0m...\n"

tests/vector_huge : tests/vector_huge.c libmds.a
	$V $(CC) $(CFLAGS) $^
	$V printf "Compiling and linking \033[1m$@\033[0m...\n"

clean : FORCE
	rm -f */*.o
	(cd tests/; rm -f `grep --colour=never -r -I -L .`)

cleanproper : clean FORCE
	rm -f *.a *.so

FORCE :
