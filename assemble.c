#include "assemble.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libs/startswith.h"
#include "libs/detect_arch.h"
#include "libs/detect_file_extension.h"
#include "libs/color.h"
#include "libs/usage.h"
#include "libs/removeCharFromString.h"

#define ARGUMENT_START 1

int assemble(char filetocompile[30], char outputFile[15], int IsDebugMode) {
    FILE *fptr;
    FILE *fptr2;
    FILE *fptrtemp;
    char line[40]/*[20]*/;
    fptr = fopen(filetocompile, "r");
    if (fptr == NULL)
    {
        printf(BRED "Error! The file is empty\n" reset);   
        exit(1);
    }
    /*fgets(line, "%s", fptr);
    printf("%s", line);*/
    int i;
    int i2;
    int posStartTo;
    int loopEndTo;
    int loopStartFrom;
    fptrtemp = fopen(outputFile, "w");
    fclose(fptrtemp);
    fptr2 = fopen(outputFile, "a");
    while (fgets(line,40, fptr)) {
        removeCharFromString('\t', line);
        i++;
        int similarity_data_section = 0;
        for (i = 0; i < 12; i++)
        {
        if ("data section"[i] == line[i])
        {
        similarity_data_section++;
        }
        }
        /*printf("similarity_data_section: %i\n", similarity_data_section);*/
        if (similarity_data_section >= 12)
        {
        fprintf(fptr2, "section .data\n");
        /*printf("written section .data\n");*/
        }
        else if (startswith("start:", line) == 1)
        {
	fprintf(fptr2, "\tglobal _start\n_start:\n");
        /*printf("written global _start\n");*/
        }
        else if(line[strlen(line) - 2] == ':' && startswith("asm", line)==0 && startswith("\tasm",line)==0){
                char functionName[10];
                memset(functionName, 0, sizeof(functionName));
                for (i = 0; i < strlen(line) - 1; i++){
                        functionName[i] = line[i];
                }
                if (IsDebugMode == 1) {
                        printf("function %s detected\n", functionName);
                }
                fprintf(fptr2, "%s", line);
        }
        else if (startswith("text section", line) == 1)
        {
        fprintf(fptr2, "section .text\n");
        }
        //MOV
        else if (startswith("move", line) || startswith("\tmove", line)) 
        {
        fprintf(fptr2, "\tmov ");
        posStartTo = 0;
        int pos;
        char movFrom[10];
        char movTo[10];
        for (pos = 5; pos < strlen(line); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line[pos] : %c\n", line[pos]);
        }
        if (line[pos] == '<') 
        {
        if (line[pos + 1] == '=') 
        {
        if (line[pos + 2] == ' ') 
        {
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
        int lengthMovTo;
        char tempWrite; 
        for (i = 5; i <= loopEndTo; i++) {
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
        }
	fprintf(fptr2, ",");
        for (i = loopStartFrom; i< strlen(line); i++) 
	{
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        }
        } 
        //CMP
	else if (startswith("compare", line) || startswith("\tcompare", line)) 
        {
        fprintf(fptr2, "\tcmp ");
        posStartTo = 0;
        int pos;
        char movFrom[10];
        char movTo[10];
        for (pos = 8; pos < strlen(line); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line[pos] : %c\n", line[pos]);
        }
        if (line[pos] == '<') 
        {
        if (IsDebugMode == 1) {
        printf("< detected\n");
        }
        if (line[pos + 1] == '=') 
        {
        if (IsDebugMode == 1) {
        printf("= detected\n");
        printf("<= detected\n");
        }
        if (line[pos + 2] == ' ') 
        {
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
        int lengthMovTo;
        char tempWrite; 
        for (i = 8; i <= loopEndTo; i++) {
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
        }
	fprintf(fptr2, ",");
        for (i = loopStartFrom; i< strlen(line); i++) 
	{
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        }
        } 
        //ADD
        else if (startswith("add", line) || startswith("\tadd", line)) 
        {
        fprintf(fptr2, "\tadd ");
        posStartTo = 0;
        int pos;
        char movFrom[10];
        char movTo[10];
        for (pos = 4; pos < strlen(line); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line[pos] : %c\n", line[pos]);
        }
        if (line[pos] == '<') 
        {
        if (IsDebugMode == 1) {
        printf("< detected\n");
        }
        if (line[pos + 1] == '=') 
        {
        if (IsDebugMode == 1) {
        printf("= detected\n");
        printf("<= detected\n");
        }
        if (line[pos + 2] == ' ') 
        {
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
        int lengthMovTo;
        char tempWrite; 
        for (i = 4; i <= loopEndTo; i++) {
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
        }
	fprintf(fptr2, ",");
        for (i = loopStartFrom; i< strlen(line); i++) 
	{
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        }
        } 
        //AND
        else if (startswith("and", line) || startswith("\tand", line)) 
        {
        fprintf(fptr2, "\tand ");
        posStartTo = 0;
        int pos;
        char movFrom[10];
        char movTo[10];
        for (pos = 3; pos < strlen(line); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line[pos] : %c\n", line[pos]);
        }
        if (line[pos] == '<') 
        {
        if (IsDebugMode == 1) {
        printf("< detected\n");
        }
        if (line[pos + 1] == '=') 
        {
        if (IsDebugMode == 1) {
        printf("= detected\n");
        printf("<= detected\n");
        }
        if (line[pos + 2] == ' ') 
        {
        loopStartFrom = pos + 3;
        } else {
        loopStartFrom = pos + 2;
        }
        /*if (line[pos - 1] == " "[0])
        {
        loopEndTo = pos - 2;
        } else {*/
        loopEndTo = pos - 1;
        /*}  */       
        }
        }
        }
        int lengthMovTo;
        char tempWrite; 
        for (i = 3; i <= loopEndTo; i++) {
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
        }
	fprintf(fptr2, ",");
        for (i = loopStartFrom; i< strlen(line); i++) 
	{
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        }
        } 
        //CALL
        else if (startswith("launch", line) || startswith("\tlaunch", line)) {
        fprintf(fptr2, "\tcall ");
        int z = 0;
        char functionName[20];
        for (i = 7; i < strlen(line); i++) {
                functionName[z] = line[i];
                z++;
        }
        
        if (startswith("start", functionName)) {
                fprintf(fptr2, "_");
        }
        posStartTo = 0;
        int pos;
        char movFrom[10];
        char movTo[10];
        for (pos = 7; pos < strlen(line); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line[pos] : %c\n", line[pos]);
        }
        fprintf(fptr2, "%c", line[pos]);
        }
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
        }
	// PUSH
	else if (startswith("push", line)||startswith("\tpush", line)){
        fprintf(fptr2,"\t");
	fprintf(fptr2,"%s",line);
	}
	// POP
	else if (startswith("pop", line)||startswith("\tpop", line)){
        fprintf(fptr2,"\t");
        fprintf(fptr2,"%s",line);
        }
	// C-FUNCTION / GLOBAL-FUNCTION
	else if (startswith("c-function",line) || startswith("global-function", line)){
	fprintf(fptr2, "extern ");
	int FirstPosFunction = startswith("c-function",line) == 1 ? 11 : 15;
	for (i = FirstPosFunction; i < strlen(line); i++){
	fprintf(fptr2, "%c", line[i]);
	}
	}
        // comments
        else if (startswith("#", line)) 
        {
        fprintf(fptr2, ";");
        for (i = 1; i < strlen(line) - 1; i++) 
        {
        fprintf(fptr2, "%c", line[i]);
        }
	fprintf(fptr2, "\n");
        }
	//INTERRUPT
        else if (startswith("interrupt", line) || startswith("\tinterrupt", line)) {
        if (IsDebugMode == 1) {
        printf("int\n");
        }
        fprintf(fptr2, "\tint ");
        int z = 0;
        posStartTo = 0;
        int pos;
        char movFrom[10];
        char movTo[10];
        for (pos = 10; pos < strlen(line); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line[pos] : %c\n", line[pos]);
        }
        fprintf(fptr2, "%c", line[pos]);
        }
        }
	//DO-NOTHING
	else if(startswith("do-nothing", line)||startswith("\tdo-nothing", line)){
	fprintf(fptr2, "\tnop\n");
	}
	//MULTIPLY
	else if(startswith("multiply", line)||startswith("\tmultiply", line)){
	fprintf(fptr2, "\tmul ");
	posStartTo = 0;
        int pos;
        char movFrom[10];
        char movTo[10];
	/*for (pos = 10; pos < strlen(line); pos++)
        {
        if (IsDebugMode == 1) {
        printf("line[pos] : %c\n", line[pos]);
        }
        if (line[pos] == '<')
        {
        if (IsDebugMode == 1) {
        printf("< detected\n");
        }
        if (line[pos + 1] ==  '=')
        {
        if (IsDebugMode == 1) {
        printf("= detected\n");
        printf("<= detected\n");
        }
        if (line[pos + 2] == ' ')
        {
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
        }*/
        int lengthMovTo;
        char tempWrite;
        for (i = 9; i <= strlen(line); i++) {
        tempWrite = line[i];
        fprintf(fptr2, "%c", tempWrite);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
        }
        /*fprintf(fptr2, ",");
	for (i = loopStartFrom; i< strlen(line); i++)
        {
        tempWrite = line[i];
        fprintf(fptr2, "%c", tempWrite);
        }*/
	}
	//RETURN
	else if (startswith("return", line) || startswith("\treturn", line)){
        if (IsDebugMode == 1) {
	printf("return\n");
        }
	fprintf(fptr2,"\tret");
	fprintf(fptr2, "\n");
	}
	//ASEMBLY CODE USAGE
	else if(startswith("asm",line) || startswith("\tasm",line)){
        if (IsDebugMode == 1) {
	    printf("asm\n");
        }
	fprintf(fptr2, "\t");
	int pos;
	for (pos = 4; pos < strlen(line); pos++) 
	{
        if (IsDebugMode == 1) {
	    printf("line[pos] : %c\n", line[pos]);
        }
        fprintf(fptr2, "%c", line[pos]);
	}
	}
    // TEST
    else if(startswith("test", line)|| startswith("\ttest", line)){
        if (IsDebugMode == 1) {
	    printf("test\n");
        }
        fprintf(fptr2, "\t");
        fprintf(fptr2, "test ");
        int pos;
        for (pos = 5; pos < strlen(line); pos++){
            
            if (line[pos] == 'a' && line[pos + 1] == 'n' && line[pos + 2] == 'd' ){
                fprintf(fptr2, ",");
                pos += 4;
                break;
            } else {
                fprintf(fptr2,"%c",line[pos]);
            }
        }
        for (pos = pos; pos < strlen(line); pos ++){
            fprintf(fptr2,"%c",line[pos]);
        }
        fprintf(fptr2, "\n");

    }
    // VARIABLES
	else
        {
        if (IsDebugMode == 1) {
        printf("line: %s", line);
        printf("strlen(line) : %li\n", strlen(line));
        }
        char line2[40];
        strcpy(line2, line);
        int c = 0;
	int posLastQuote;
	int posFirstQuote;
	int sizeLineList = 0;
        char lineList[10][10];
	char *pch = strtok(line," ");
	memset(lineList,0,sizeof(lineList));
	while (pch != NULL)
	{
	sizeLineList++;
        if (IsDebugMode == 1) {
    	printf ("pch : %s\n",pch);
        printf("startswith(pch) : %i\n",startswith("\"", pch));
        }
	if (startswith("\"", pch)) 
	{
	for (i = 0; i < strlen(line2); i++)
  	{
  	if(line2[i] == '"')  
	{
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
	for (i = posFirstQuote + 1; i < strlen(line2); i++)
        {
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
	for (i = posFirstQuote; i < posLastQuote; i++) 
	{
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
	else 
	{
	strcpy(lineList[c], pch);
    	//pch = strtok (NULL, " \t");
	pch = strtok (NULL, " ");
	}
	c++;
	}
	int d= 0;
	/*while (lineList[d] != "") 
	{
	sizeLineList++;
	d++;
	}*/
	/*
        for (i = 0; i < sizeLineList; i++)
        {
        printf("lineList: %s", lineList[i]);
	fprintf(fptr2, "%s ",lineList[i]);
        }*/
	// CHAR
	if (startswith("char", lineList[1])) 
	{
	fprintf(fptr2, "%s ", lineList[0]);
	fprintf(fptr2, "DB ");
        if (IsDebugMode == 1) {
        printf("lineList[2] %s\n ", lineList[sizeLineList]);
        }
	fprintf(fptr2, "%s ", lineList[sizeLineList]);
	}
	// TWOCHAR
	else if (startswith("twoChar", lineList[1])) 
	{
	fprintf(fptr2, "%s ", lineList[0]);
	fprintf(fptr2, "DW ");
        if (IsDebugMode == 1) {
        printf("lineList[2] %s\n ", lineList[2]);
        }
	fprintf(fptr2, "%s ", lineList[sizeLineList]);
	}
	// FOURCHAR
        else if (startswith("fourChar", lineList[1]))
	{
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
        printf("%s\n", line);
        }
    }
    fprintf(fptr2, "\n");
    //fprintf(fptr2, "\tret\n");
    fclose(fptr);
    fclose(fptr2);
    return 0;
}