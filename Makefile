CC=gcc
TARGET=sasm
FLAGS=-Wstring-compare -Wformat

all:
	mkdir build
	$(CC) -c -g libs/startswith.c -o build/startswith.o
	$(CC) -c -g libs/detect_arch.c -o build/detect_arch.o
	$(CC) -c -g libs/detect_file_extension.c -o build/detect_file_extension.o
	$(CC) -c -g libs/usage.c -o build/usage.o
	$(CC) -c -g main.c -o build/main.o
	$(CC) -o sasm build/main.o build/startswith.o build/detect_arch.o build/detect_file_extension.o build/usage.o
	rm -rf build



clean:
	rm -rf $(TARGET) build
run:
	./sasm test.sasm
test:
	mkdir build
	$(CC) -c -g libs/startswith.c -o build/startswith.o
	$(CC) -c -g libs/detect_arch.c -o build/detect_arch.o
	$(CC) -c -g tests/test.c -o build/test.o
	$(CC) -o sasm-tests build/test.o build/startswith.o build/detect_arch.o
	rm -rf build

windows:
	mkdir build
	$(CC) -c -g libs/startswith.c -o build/startswith.o
	$(CC) -c -g libs/detect_arch.c -o build/detect_arch.o
	$(CC) -c -g libs/detect_file_extension.c -o build/detect_file_extension.o
	$(CC) -c -g libs/usage.c -o build/usage.o
	$(CC) -c -g main.c -o build/main.o
	$(CC) -o sasm.exe build/main.o build/startswith.o build/detect_arch.o build/detect_file_extension.o build/usage.o
	rmdir .\build\ /s /q


install:
	cp sasm /usr/bin/sasm

uninstall:
	rm /usr/bin/sasm
