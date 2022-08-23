CC=gcc
TARGET=sasm
FLAGS=-Wstring-compare -Wformat

all:
	mkdir build
	$(CC) -c -g libs/startswith.c -o build/startswith.o
	$(CC) -c -g libs/detect_arch.c -o build/detect_arch.o
	$(CC) -c -g libs/file.c -o build/file.o
	$(CC) -c -g libs/removeCharFromString.c -o build/removeCharFromString.o
	$(CC) -c -g libs/usage.c -o build/usage.o
	$(CC) -c -g main.c -o build/main.o
	$(CC) -c -g assemble.c -o build/assemble.o
	$(CC) -o sasm build/main.o build/startswith.o build/detect_arch.o build/file.o build/usage.o build/assemble.o build/removeCharFromString.o
	rm -rf build



clean:
	rm -rf $(TARGET) build sasm-tests code.asm examples/*.asm examples/*.o
	make -C tests clean
run:
	./sasm test.sasm -d
test:
	make -C tests

run_test:
	./tests/sasm-tests

windows:
	mkdir build
	$(CC) -c -g libs/startswith.c -o build/startswith.o
	$(CC) -c -g libs/detect_arch.c -o build/detect_arch.o
	$(CC) -c -g libs/file.c -o build/file.o
	$(CC) -c -g libs/removeCharFromString.c -o build/removeCharFromString.o
	$(CC) -c -g libs/usage.c -o build/usage.o
	$(CC) -c -g main.c -o build/main.o
	$(CC) -c -g assemble.c -o build/assemble.o
	$(CC) -o sasm.exe build/main.o build/startswith.o build/detect_arch.o build/file.o build/usage.o build/assemble.o build/removeCharFromString.o
	rmdir .\build\ /s /q


install:
	cp sasm /usr/bin/sasm

uninstall:
	rm /usr/bin/sasm
