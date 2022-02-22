CC=gcc
TARGET=main.out
FLAGS=-Wstring-compare -Wformat

all:
	mkdir build
	$(CC) -c -g libs/startswith.c -o build/startswith.o
	$(CC) -c -g libs/detect_arch.c -o build/detect_arch.o
	$(CC) -c -g main.c -o build/main.o
	$(CC) -o sasm build/main.o build/startswith.o build/detect_arch.o
	rm -rf build

old:
	$(CC) main.c -o $(TARGET) $(FLAGS)


clean:
	rm $(TARGET)
run:
	./sasm test.sasm
test:
	$(CC) -c -g libs/startswith.c -o libs/startswith.o
	$(CC) -c -g tests/test.c -o tests/test.o
	$(CC) -o test.out tests/test.o libs/startswith.o

windows:
	mkdir build
	$(CC) -c -g libs/startswith.c -o build/startswith.o
	$(CC) -c -g libs/detect_arch.c -o build/detect_arch.o
	$(CC) -c -g main.c -o build/main.o
	$(CC) -o sasm.exe build/main.o build/startswith.o build/detect_arch.o
	rmdir .\build\ /s /q


install:
	cp sasm /usr/bin/sasm
