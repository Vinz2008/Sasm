gcc -c -g startswith.c
gcc -c -g test.c
gcc -o test.bin test.o startswith.o
