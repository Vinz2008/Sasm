#include "emulator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/startswith.h"
#include "libs/removeCharFromString.h"

struct Registers registers;


void init_registers(struct Registers registers){
	registers.eax = 0;
	registers.ebx = 0;
	registers.ecx = 0;
	registers.edx = 0;
}

_register* strToRegister(char* reg){
	if (strcmp(reg, "eax") == 0){
		return &registers.eax;
	} else if (startswith("ebx", reg)){
		printf("ebx\n");
		return &registers.ebx;
	} else if (strcmp(reg, "ecx") == 0){
		return &registers.ecx;
	} else if (strcmp(reg, "edx") == 0){
		return &registers.edx;
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

void emulate(char* inputFile, char* outputFile, int IsDebugMode){
	init_registers(registers);
	struct Stack stack;
	stack.stackList = malloc(10 * sizeof(StackEntry));
	FILE* fptrTemp = fopen(outputFile, "w");
	fclose(fptrTemp);
	FILE* fptrOut = fopen(outputFile, "a");
	FILE* fptrIn = fopen(inputFile, "r");
	char line[40];
	int i;
	while (fgets(line,40, fptrIn)) {
		removeCharFromString('\t', line);
		if (IsDebugMode == 1) {
            printf ("line: %s\n", line);
        }
		char line2[40];
        strcpy(line2, line);
		int sizeLineList = 0;
		int posLastQuote;
		int posFirstQuote;
		char lineList[10][10];
		int c = 0;
		char *pch = strtok(line," ");
		memset(lineList,0,sizeof(lineList));
		while (pch != NULL){
		sizeLineList++;
		if (startswith("\"", pch)) {
			for (i = 0; i < strlen(line2); i++){
  			if(line2[i] == '"')  {
			posFirstQuote = i;
        	if (IsDebugMode == 1) {
                printf ("posFirstQuote: %i\n", posFirstQuote);
        	}
			break;    	
 			}
			}
        	if (IsDebugMode == 1) {
        	printf("strlen(line2) : %li\n", strlen(line2));
        	}
			for (i = posFirstQuote + 1; i < strlen(line2); i++){
        	if(line2[i] == '"'){
        	posLastQuote = i + 1;
        	if (IsDebugMode == 1) {
        	printf ("posLastQuote: %i\n", posLastQuote);
        	}
        	break;
        	}
        	}
        	int w = 0;
			for (i = posFirstQuote; i < posLastQuote; i++){
			lineList[sizeLineList][w] = line2[i]; 
        	if (IsDebugMode == 1) {
        	printf("lineList[sizeLineList] %s\n", lineList[sizeLineList]);
        	}
        	w++;
			}
			break;
		} else {
			strcpy(lineList[c], pch);
			pch = strtok (NULL, " ");
		}
		c++;
		}
		if (IsDebugMode == 1) {
		printf("lineList[0] : %s\n", lineList[0]);
		}
		if (startswith("add", lineList[0])){
			_register* tempPtr1 =  strToRegister(lineList[1]);
			printf("lineList[3] : %s\n", lineList[3]);
			_register* tempPtr2 = strToRegister(lineList[3]);
			printf("*tempPtr : %d\n", *tempPtr1);
			//*tempPtr = *tempPtr + *tempPtr2;
			printf("*tempPtr2 : %d\n", *tempPtr2);
			_register* tempPtr3;
			printf("result : %d\n", *tempPtr1 + *tempPtr2);
			*tempPtr3 = *tempPtr1 + *tempPtr2;
			printf("TEST \n");
			*tempPtr1 = *tempPtr3;
		}
	}
	fclose(fptrIn);
	fclose(fptrOut);
	showRegisters(registers);
}

