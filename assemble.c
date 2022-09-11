#include "assemble.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "instructions_handlers.h"
#include "libs/startswith.h"
#include "libs/detect_arch.h"
#include "libs/file.h"
#include "libs/color.h"
#include "libs/usage.h"
#include "libs/removeCharFromString.h"

int assemble(char* filetocompile, char* outputFile, int IsDebugMode, int IsNasmMode, int IsLdMode, int IsEmulating) {
    FILE *fptr;
    FILE *fptr2;
    FILE *fptrtemp;
    char line[40];
    fptr = fopen(filetocompile, "r");
    if (fptr == NULL){
        printf(BRED "Error! The file is empty\n" reset);
        exit(1);
    }
    int i;
    int posStartTo = -1;
    int loopEndTo = -1;
    int loopStartFrom = -1;
    fptrtemp = fopen(outputFile, "w");
    fclose(fptrtemp);
    fptr2 = fopen(outputFile, "a");
    while (fgets(line,40, fptr)) {
        char line2[40];
        strcpy(line2, line);
        int c = 0;
		int posLastQuote = -1;
		int posFirstQuote = -1;
		int sizeLineList = 0;
        char lineList[10][10];
		char *pch = strtok(line," ");
		memset(lineList,0,sizeof(lineList));
		while (pch != NULL){
		sizeLineList++;
        if (IsDebugMode == 1) {
    	printf ("pch : %s\n",pch);
        printf("startswith(pch) : %i\n",startswith("\"", pch));
        }
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
        if(line2[i] == '"')
        {
        posLastQuote = i + 1;
        if (IsDebugMode == 1) {
        printf ("posLastQuote: %i\n", posLastQuote);
        }
        break;
        }
        }
        int w = 0;
        //printf("lineList[sizeLineList] : %s", lineList[sizeLineList]);
	for (i = posFirstQuote; i < posLastQuote; i++){
	lineList[sizeLineList][w] = line2[i]; 
        if (IsDebugMode == 1) {
        printf("lineList[sizeLineList] %s\n", lineList[sizeLineList]);
        }
        w++;
	}
        //lineList[sizeLineList][w] = "\0";
	break;
	}
        else if(startswith("1", pch)||startswith("2", pch)||startswith("3", pch)||startswith("4", pch)||startswith("5", pch)||startswith("6", pch)||startswith("7", pch)||startswith("8", pch)||startswith("9", pch)||startswith("10", pch)){
                strcpy(lineList[sizeLineList], pch);
                break; 
        }
	else{
	strcpy(lineList[c], pch);
	pch = strtok (NULL, " ");
	}
	c++;
	}
    if (strcmp(line2, "\n") != 0 || strcmp(line2,"\r\n") != 0){
        removeCharFromString('\t', line2);
        i++;
		if (startswith("data", lineList[0]) && startswith("section", lineList[1])){
		fprintf(fptr2, "section .data\n");
		}
        else if (startswith("start:", lineList[0]) == 1){
		fprintf(fptr2, "\tglobal _start\n_start:\n");
        }
        else if(line2[strlen(line2) - 2] == ':' && startswith("asm", lineList[0])==0 && startswith("\tasm",lineList[0])==0){
        char functionName[10];
        memset(functionName, 0, sizeof(functionName));
        for (i = 0; i < strlen(line2) - 1; i++){
            functionName[i] = line2[i];
        }
                if (IsDebugMode == 1) {
                        printf("function %s detected\n", functionName);
                }
                fprintf(fptr2, "%s", line2);
        }
        else if (startswith("code section", line2) == 1){
        	code_section_handler(fptr2, 0);
        }
        else if(startswith("variable section", line2)){
        	variable_section_handler(fptr2, 0);
        }
        //MOV
        else if (startswith("move", line2)){
            move_handler(line2, fptr2, IsDebugMode, 0);
        } 
        //CMP
		else if (startswith("compare", line2)){
			compare_handler(line2, fptr2, IsDebugMode, 0);
        }
        //ADD
        else if (startswith("add", line2)){
        fprintf(fptr2, "\tadd ");
        posStartTo = 0;
        int pos;
        for (pos = 4; pos < strlen(line2); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line2[pos] : %c\n", line2[pos]);
        }
        if (line2[pos] == '<'){
        if (IsDebugMode == 1) {
        printf("< detected\n");
        }
        if (line2[pos + 1] == '='){
        if (IsDebugMode == 1) {
        printf("= detected\n");
        printf("<= detected\n");
        }
        if (line2[pos + 2] == ' '){
        loopStartFrom = pos + 3;
        } else {
        loopStartFrom = pos + 2;
        }
        if (line2[pos - 1] == ' ')
        {
        loopEndTo = pos - 2;
        } else {
        loopEndTo = pos - 1;
        }         
        }
        }
        }
        char tempWrite; 
        for (i = 4; i <= loopEndTo; i++) {
        tempWrite = line2[i];
	fprintf(fptr2, "%c", tempWrite);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
        }
	fprintf(fptr2, ",");
        for (i = loopStartFrom; i< strlen(line2); i++) 
	{
        tempWrite = line2[i];
	fprintf(fptr2, "%c", tempWrite);
        }
        } 
        //AND
        else if (startswith("and", line2)) 
        {
        fprintf(fptr2, "\tand ");
        posStartTo = 0;
        int pos;
        for (pos = 3; pos < strlen(line2); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line2[pos] : %c\n", line2[pos]);
        }
        if (line2[pos] == '<') 
        {
        if (IsDebugMode == 1) {
        printf("< detected\n");
        }
        if (line2[pos + 1] == '=') 
        {
        if (IsDebugMode == 1) {
        printf("= detected\n");
        printf("<= detected\n");
        }
        if (line2[pos + 2] == ' ') 
        {
        loopStartFrom = pos + 3;
        } else {
        loopStartFrom = pos + 2;
        }
        loopEndTo = pos - 1;      
        }
        }
        }
        char tempWrite; 
        for (i = 3; i <= loopEndTo; i++) {
        tempWrite = line2[i];
	fprintf(fptr2, "%c", tempWrite);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
        }
	fprintf(fptr2, ",");
        for (i = loopStartFrom; i< strlen(line2); i++) 
	{
        tempWrite = line2[i];
	fprintf(fptr2, "%c", tempWrite);
        }
        } 
        //CALL
        else if (startswith("launch", line2)) {
        fprintf(fptr2, "\tcall ");
        int z = 0;
        char functionName[20];
        for (i = 7; i < strlen(line2); i++) {
                functionName[z] = line2[i];
                z++;
        }
        
        if (startswith("start", functionName)) {
                fprintf(fptr2, "_");
        }
        posStartTo = 0;
        int pos;
        for (pos = 7; pos < strlen(line2); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line2[pos] : %c\n", line2[pos]);
        }
        fprintf(fptr2, "%c", line2[pos]);
        }
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
        }
	// PUSH
	else if (startswith("push", line2)){
        fprintf(fptr2,"\t");
	fprintf(fptr2,"%s",line2);
	}
	// POP
	else if (startswith("pop", line2)){
        fprintf(fptr2,"\t");
        fprintf(fptr2,"%s",line2);
        }
	// C-FUNCTION / GLOBAL-FUNCTION
	else if (startswith("c-function",line2) || startswith("global-function", line2)){
	fprintf(fptr2, "extern ");
	int FirstPosFunction = startswith("c-function",line2) == 1 ? 11 : 15;
	for (i = FirstPosFunction; i < strlen(line2); i++){
	fprintf(fptr2, "%c", line2[i]);
	}
	}
        // comments
        else if (startswith("#", line2)) 
        {
        fprintf(fptr2, ";");
        for (i = 1; i < strlen(line2) - 1; i++) 
        {
        fprintf(fptr2, "%c", line2[i]);
        }
	fprintf(fptr2, "\n");
        }
	//INTERRUPT
        else if (startswith("interrupt", line2)) {
        if (IsDebugMode == 1) {
        printf("int\n");
        }
        fprintf(fptr2, "\tint ");
        posStartTo = 0;
        int pos;
        for (pos = 10; pos < strlen(line2); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line2[pos] : %c\n", line2[pos]);
        }
        fprintf(fptr2, "%c", line2[pos]);
        }
        }
	//DO-NOTHING
	else if(startswith("do-nothing", line2)){
	fprintf(fptr2, "\tnop\n");
	}
	//MULTIPLY
	else if(startswith("multiply", line2)){
	fprintf(fptr2, "\tmul ");
	posStartTo = 0;
    char tempWrite;
    for (i = 9; i <= strlen(line2); i++) {
        tempWrite = line2[i];
        fprintf(fptr2, "%c", tempWrite);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
    }
	}
	//RETURN
	else if (startswith("return", line2)){
        if (IsDebugMode == 1) {
	printf("return\n");
        }
	fprintf(fptr2,"\tret");
	fprintf(fptr2, "\n");
	}
	//ASEMBLY CODE USAGE
	else if(startswith("asm",line2)){
        if (IsDebugMode == 1) {
	    printf("asm\n");
        }
	fprintf(fptr2, "\t");
	int pos;
	for (pos = 4; pos < strlen(line2); pos++) 
	{
        if (IsDebugMode == 1) {
	    printf("line2[pos] : %c\n", line2[pos]);
        }
        fprintf(fptr2, "%c", line2[pos]);
	}
	}
    // TEST
    else if(startswith("test", line2)){
        if (IsDebugMode == 1) {
	    printf("test\n");
        }
        fprintf(fptr2, "\t");
        fprintf(fptr2, "test ");
        int pos;
        for (pos = 5; pos < strlen(line2); pos++){
            
            if (line2[pos + 1] == 'a' && line2[pos + 2] == 'n' && line2[pos + 3] == 'd' ){
                fprintf(fptr2, ",");
                pos += 4;
                break;
            } else {
                fprintf(fptr2,"%c",line2[pos]);
            }
        }
        for (pos = pos; pos < strlen(line2); pos ++){
            fprintf(fptr2,"%c",line2[pos]);
        }

    }
    else if(startswith("jumpzeroflag", line2)){
            fprintf(fptr2, "\tjnz ");
            int pos;
            for (pos = 11; pos < strlen(line2); pos++){ 
                fprintf(fptr2,"%c",line2[pos]);
            }
    }
    // VARIABLES
    else{
    	if (IsDebugMode == 1) {
        printf("line2: %s", line2);
        printf("strlen(line2) : %li\n", strlen(line2));
        }
        
	// CHAR
	if (startswith("char", lineList[1])){
	        fprintf(fptr2, "%s ", lineList[0]);
		fprintf(fptr2, "DB ");
                if (IsDebugMode == 1) {
                printf("lineList[2] %s\n ", lineList[sizeLineList]);
                }
		fprintf(fptr2, "%s ", lineList[sizeLineList]);
	}
	// TWOCHAR
	else if (startswith("twoChar", lineList[1])){
		fprintf(fptr2, "%s ", lineList[0]);
		fprintf(fptr2, "DW ");
        if (IsDebugMode == 1) {
        printf("lineList[2] %s\n ", lineList[2]);
        }
		fprintf(fptr2, "%s ", lineList[sizeLineList]);
	}
	// FOURCHAR
    else if (startswith("fourChar", lineList[1])){
		fprintf(fptr2, "%s ", lineList[0]);
        if (IsDebugMode == 1) {
		printf("lineList[0] %s\n", lineList[0]);
        }
		fprintf(fptr2, "DD ");
        if (IsDebugMode == 1) {
		printf("lineList[2] %s\n ", lineList[sizeLineList]);
    	}
		fprintf(fptr2, "%s ", lineList[sizeLineList]);
	}
	fprintf(fptr2, "\n");
    if (IsDebugMode == 1) {
	printf("backslash n\n");
    }
	memset(lineList,0,sizeof(lineList));
    }
    if (IsDebugMode == 1) {
    printf("%s\n", line2);
    }
    }
    }
    fprintf(fptr2, "\n");
    fclose(fptr);
    fclose(fptr2);
    if (IsNasmMode == 1){
        char* temp = malloc(50 * sizeof(char));
        sprintf(temp, "nasm -f elf %s -o code.o", outputFile);
        system(temp);
        free(temp);
    }
    if (IsLdMode == 1){
        char* temp2 = malloc(100 * sizeof(char));
        sprintf(temp2, "ld code.o -o %s", removeFileExtension("code.o"));
        system(temp2);
        free(temp2);
    }
    return 0;
}
