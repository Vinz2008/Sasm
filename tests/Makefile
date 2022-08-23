CC=gcc
CFLAGS=-c -g

all: setup sasm-files test-files sasm-tests clean-build


setup: clean-build 
	mkdir build

sasm-files: build/startswith.o build/removeCharFromString.o build/file.o

build/startswith.o:
	$(CC) $(CFLAGS) ../libs/startswith.c -o build/startswith.o

build/removeCharFromString.o:
	$(CC) $(CFLAGS) ../libs/removeCharFromString.c -o build/removeCharFromString.o

build/file.o:
	$(CC) $(CFLAGS) ../libs/file.c -o build/file.o

test-files: build/test_startswith.o build/test_removeCharFromString.o build/test_file.o build/test.o

build/test_startswith.o:
	$(CC) $(CFLAGS) test_startswith.c -o build/test_startswith.o

build/test_removeCharFromString.o:
	$(CC) $(CFLAGS) test_removeCharFromString.c -o build/test_removeCharFromString.o

build/test_file.o:
	$(CC) $(CFLAGS) test_file.c -o build/test_file.o

build/test.o:
	$(CC) $(CFLAGS) test.c -o build/test.o

sasm-tests:
	$(CC) -o sasm-tests build/startswith.o build/removeCharFromString.o build/file.o build/test_startswith.o build/test_removeCharFromString.o build/test_file.o build/test.o 

clean-build:
	rm -rf build

clean:
	rm -rf build sasm-tests