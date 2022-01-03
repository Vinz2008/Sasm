CC=gcc
TARGET=main.o
FLAGS=-Wstring-compare -Wformat


all:
	$(CC) main.c -o $(TARGET) $(FLAGS)

clean:
	rm $(TARGET)
	rm ./*.o

run:
	./$(TARGET)
