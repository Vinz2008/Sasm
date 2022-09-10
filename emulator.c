#include "emulator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/startswith.h"
#include "libs/removeCharFromString.h"

struct Registers registers;
struct Stack stack;

void init_registers(struct Registers registers){
	registers.eax = 1;
	registers.ebx = 2;
	registers.ecx = 3;
	registers.edx = 4;
}

void setRegister(uint16_t value, char* reg){
	if (strcmp(reg, "eax") == 0){
		registers.eax = value;
	} else if (startswith("ebx", reg)){
		registers.ebx = value;
	} else if (strcmp(reg, "ecx") == 0){
		registers.ecx = value;
	} else if (strcmp(reg, "edx") == 0){
		registers.edx = value;
	} else {
		printf("ERROR : can't find register %s\n", reg);
		exit(1);
	}
}

_register getRegister(char* reg){
	if (strcmp(reg, "eax") == 0){
		return registers.eax;
	} else if (startswith("ebx", reg)){
		return registers.ebx;
	} else if (strcmp(reg, "ecx") == 0){
		return registers.ecx;
	} else if (strcmp(reg, "edx") == 0){
		return registers.edx;
	} else {
		printf("ERROR : can't find register %s\n", reg);
		exit(1);
	}
}

void showRegisters(struct Registers registers){
	printf("eax : %d\n", registers.eax);
	printf("ebx : %d\n", registers.ebx);
	printf("ecx : %d\n", registers.ecx);
	printf("edx : %d\n", registers.edx);
}

/*
void add_handler_emulator(char line[]){
	printf("reg1 : %d\n", getRegister(lineList[1]));
	setRegister(getRegister(lineList[1]) + getRegister(lineList[3]), lineList[1]);
	printf("result : %d\n", getRegister(lineList[1]) + getRegister(lineList[3]));
	printf("TEST \n");
}
*/

void move_handler_emulator(char line[], FILE* fptr, int IsDebugMode, int isEmulating){
	
}

void init_emulator(char* inputFile, char* outputFile, int IsDebugMode){
	init_registers(registers);
	stack.stackList = malloc(10 * sizeof(StackEntry));
	showRegisters(registers);
}

