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

int isRegister(char* reg){
	if (!(strcmp(reg, "eax") == 0 || startswith("ebx", reg) || strcmp(reg, "ecx") == 0 || strcmp(reg, "edx") == 0)){
		return 0;
	}
	return 1;
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

void move_handler_emulator(char line[], int IsDebugMode){
	_register value;
	int pos;
    int loopStartFrom = 0;
    int loopEndTo = 0;
    int i;
    for (pos = 5; pos < strlen(line); pos++){
    if (IsDebugMode == 1) {
        printf("line[pos] : %c\n", line[pos]);
    }
    if (line[pos] == '<'){
    if (line[pos + 1] == '='){
    if (line[pos + 2] == ' '){
        loopStartFrom = pos + 3;
    } else {
        loopStartFrom = pos + 2;
    }
    if (line[pos - 1] == ' '){
        loopEndTo = pos - 2;
    } else {
        loopEndTo = pos - 1;
    }
    }
    }
    }
	char reg1[4];
    for (i = 5; i <= loopEndTo; i++) {
	    //fprintf(fptr, "%c", line[i]);
		strncat(reg1, &line[i], 1);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
    }
	char reg2[4];
	//fprintf(fptr, ",");
    for (i = loopStartFrom; i < strlen(line); i++) {
		strncat(reg2, &line[i], 1);
	    //fprintf(fptr, "%c", line[i]);
    }
	printf("reg1 : %s\n reg2 : %s\n", reg1, reg2);
	if (isRegister(reg2) == 1){
		value = getRegister(reg2);
	} else {
		char *ptr;
		value = strtol(reg2, &ptr, 10);
	}
	setRegister(value, reg1);
	showRegisters(registers);
}

void add_handler_emulator(char line[], int IsDebugMode){
	printf("ADD EMULATOR\n");
	int i;
    int loopStartFrom = 0;
    int loopEndTo = 0;
    int posStartTo = 0;
    int pos;
    for (pos = 4; pos < strlen(line); pos++){
        if (IsDebugMode == 1) {
        printf("line2[pos] : %c\n", line[pos]);
        }
        if (line[pos] == '<'){
        if (IsDebugMode == 1) {
        printf("< detected\n");
        }
        if (line[pos + 1] == '='){
        if (IsDebugMode == 1) {
        printf("= detected\n");
        printf("<= detected\n");
        }
        if (line[pos + 2] == ' '){
        loopStartFrom = pos + 3;
        } else {
        loopStartFrom = pos + 2;
        }
        if (line[pos - 1] == ' ')
        {
        loopEndTo = pos - 2;
        } else {
        loopEndTo = pos - 1;
        }         
        }
        }
    }
    char tempWrite;
	char reg1[4];
    for (i = 4; i <= loopEndTo; i++) {
        tempWrite = line[i];
		strncat(reg1, &line[i], 1);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
    }
	char reg2[4];
    for (i = loopStartFrom; i< strlen(line); i++) {
        tempWrite = line[i];
		strncat(reg2, &line[i], 1);
    }
	printf("reg1: %s\n reg2 : %s\n", reg1, reg2);
	_register value = getRegister(reg1) + getRegister(reg2);
	printf("value : %d\n", getRegister(reg1));
	setRegister(value, reg1);
	showRegisters(registers);
}

void init_emulator(char* inputFile, char* outputFile, int IsDebugMode){
	init_registers(registers);
	stack.stackList = malloc(10 * sizeof(StackEntry));
	showRegisters(registers);
}

