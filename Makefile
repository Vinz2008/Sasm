CC=gcc
TARGET=main.o
FLAGS=-Wstring-compare -Wformat

all:
	$(CC) -c -g startswith.c
	$(CC) -c -g main.c
	$(CC) -o main.out main.o startswith.o

old:
	$(CC) main.c -o $(TARGET) $(FLAGS)


clean:
	rm $(TARGET)
	rm ./*.o

run:
	./main.out test.sasm
test:
	$(CC) -c -g startswith.c
	$(CC) -c -g test.c
	$(CC) -o test.bin test.o startswith.o
