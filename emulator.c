#include "emulator.h"
#include <stdio.h>
#include <stdlib.h>

void emulate(char* inputFile, char* outputFile, int IsDebug){
	struct Registers registers;
	struct Stack stack;
	stack.stackList = malloc(10 * sizeof(StackEntry));
	FILE* fptrTemp = fopen(outputFile, "w");
	fclose(fptrTemp);
	FILE* fptrOut = fopen(outputFile, "a");
	FILE* fptrIn = fopen(inputFile, "r");
}

