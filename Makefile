CC=gcc
TARGET=sasm
CFLAGS=-c -g -Wall -O2

OBJS=\
libs/startswith.o \
libs/detect_arch.o \
libs/removeCharFromString.o \
libs/file.o \
libs/usage.o \
arch/i386/instructions_handlers_i386.o \
instructions_handlers.o \
emulator.o \
assemble.o \
main.o \



all: sasm 


sasm : $(OBJS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $^

clean-build:
ifeq ($(OS),Windows_NT)
	rmdir .\*.o .\libs\*.o /s /q
else
	rm -rf ./*.o ./libs/*.o
endif

clean: clean-build
	rm -rf $(TARGET) sasm-tests code.asm examples/*.asm examples/*.o
	make -C tests clean
run:
	./sasm test.sasm -d
test:
	make -C tests

run_test:
	./tests/sasm-tests

install:
	cp sasm /usr/bin/sasm

uninstall:
	rm /usr/bin/sasm
