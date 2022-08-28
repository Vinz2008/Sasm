CC=gcc
TARGET=sasm
CFLAGS=-c -g -Wall -O2

all: setup build/startswith.o build/detect_arch.o build/file.o build/removeCharFromString.o build/usage.o build/instructions_handlers.o build/emulator.o build/main.o build/assemble.o sasm clean-build

setup:
ifeq ($(OS),Windows_NT)
	rmdir .\build\ /s /q
else
	rm -rf build
endif
	mkdir build

build/startswith.o:
	$(CC) $(CFLAGS) libs/startswith.c -o build/startswith.o

build/detect_arch.o:
	$(CC) $(CFLAGS) libs/detect_arch.c -o build/detect_arch.o

build/file.o:
	$(CC) $(CFLAGS) libs/file.c -o build/file.o

build/removeCharFromString.o:
	$(CC) $(CFLAGS) libs/removeCharFromString.c -o build/removeCharFromString.o

build/usage.o:
	$(CC) $(CFLAGS) libs/usage.c -o build/usage.o

build/instructions_handlers.o:
	$(CC) $(CFLAGS) instructions_handlers.c -o build/instructions_handlers.o

build/emulator.o:
	$(CC) $(CFLAGS) emulator.c -o build/emulator.o

build/main.o:
	$(CC) $(CFLAGS) main.c -o build/main.o

build/assemble.o:
	$(CC) $(CFLAGS) assemble.c -o build/assemble.o

sasm:
	$(CC) -o sasm build/main.o build/emulator.o build/instructions_handlers.o build/startswith.o build/detect_arch.o build/file.o build/usage.o build/assemble.o build/removeCharFromString.o
	rm -rf build

clean-build:
ifeq ($(OS),Windows_NT)
	rmdir .\build\ /s /q
else
	rm -rf build
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
