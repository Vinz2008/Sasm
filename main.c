#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libs/startswith.h"
#include "libs/detect_arch.h"
#include "libs/detect_file_extension.h"
#include "libs/color.h"
#include "libs/usage.h"

/*#ifdef _WIN32
#define ARGUMENT_START 1
#else
#define ARGUMENT_START 0
#endif
*/
#define ARGUMENT_START 1

int compile(char filetocompile[20]) {
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
    int posStartTo;
    int loopEndTo;
    int loopStartFrom;
    fptrtemp = fopen("code.asm", "w");
    fclose(fptrtemp);
    fptr2 = fopen("code.asm", "a");
    while (fgets(line,150, fptr)) {
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
        else if (startswith("start", line) == 1)
        {
	fprintf(fptr2, "\tglobal _start\n_start:\n");
        /*printf("written global _start\n");*/
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
        for (pos = 6; pos < strlen(line); pos++)
        {
        printf("line[pos] : %c\n", line[pos]);
        if (line[pos] == "<"[0]) 
        {
        if (line[pos + 1] == "="[0]) 
        {
        if (line[pos + 2] == " "[0]) 
        {
        loopStartFrom = pos + 3;
        } else {
        loopStartFrom = pos + 2;
        }
        if (line[pos - 1] == " "[0])
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
        for (i = 6; i <= loopEndTo; i++) {
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        printf("i: %i\n", i);
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
        for (pos = 9; pos < strlen(line); pos++)
        {
        printf("line[pos] : %c\n", line[pos]);
        if (line[pos] == "<"[0]) 
        {
        printf("< detected\n");
        if (line[pos + 1] == "="[0]) 
        {
        printf("= detected\n");
        printf("<= detected\n");
        if (line[pos + 2] == " "[0]) 
        {
        loopStartFrom = pos + 3;
        } else {
        loopStartFrom = pos + 2;
        }
        if (line[pos - 1] == " "[0])
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
        for (i = 9; i <= loopEndTo; i++) {
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        printf("i: %i\n", i);
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
        for (pos = 5; pos < strlen(line); pos++)
        {
        printf("line[pos] : %c\n", line[pos]);
        if (line[pos] == "<"[0]) 
        {
        printf("< detected\n");
        if (line[pos + 1] == "="[0]) 
        {
        printf("= detected\n");
        printf("<= detected\n");
        if (line[pos + 2] == " "[0]) 
        {
        loopStartFrom = pos + 3;
        } else {
        loopStartFrom = pos + 2;
        }
        if (line[pos - 1] == " "[0])
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
        printf("i: %i\n", i);
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
        for (pos = 5; pos < strlen(line); pos++)
        {
        printf("line[pos] : %c\n", line[pos]);
        if (line[pos] == "<"[0]) 
        {
        printf("< detected\n");
        if (line[pos + 1] == "="[0]) 
        {
        printf("= detected\n");
        printf("<= detected\n");
        if (line[pos + 2] == " "[0]) 
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
        for (i = 5; i <= loopEndTo; i++) {
        tempWrite = line[i];
	fprintf(fptr2, "%c", tempWrite);
        printf("i: %i\n", i);
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
        for (i = 8; i < strlen(line); i++) {
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
        for (pos = 8; pos < strlen(line); pos++)
        {
        printf("line[pos] : %c\n", line[pos]);
        fprintf(fptr2, "%c", line[pos]);
        }
        printf("i: %i\n", i);
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
        printf("int\n");
        fprintf(fptr2, "\tint ");
        int z = 0;
        posStartTo = 0;
        int pos;
        char movFrom[10];
        char movTo[10];
        for (pos = 11; pos < strlen(line); pos++)
        {
        printf("line[pos] : %c\n", line[pos]);
        fprintf(fptr2, "%c", line[pos]);
        }
        }

	//RETURN
	else if (startswith("return", line) || startswith("\treturn", line)){
	printf("return\n");
	fprintf(fptr2,"\tret");
	fprintf(fptr2, "\n");
	}
	//ASEMBLY CODE USAGE
	else if(startswith("asm",line) || startswith("\tasm",line)){
	printf("asm\n");
	fprintf(fptr2, "\t");
	int pos;
	for (pos = 5; pos < strlen(line); pos++) 
	{
	printf("line[pos] : %c\n", line[pos]);
        fprintf(fptr2, "%c", line[pos]);
	}
	}
	else
        {
        printf("line: %s", line);
        printf("strlen(line) : %li\n", strlen(line));
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
    	printf ("pch : %s\n",pch);
        printf("startswith(pch) : %i\n",startswith("\"", pch));
	if (startswith("\"", pch)) 
	{
	for (i = 0; i < strlen(line2); i++)
  	{
  	if(line2[i] == '"')  
	{
	posFirstQuote = i;

        printf ("posFirstQuote: %i\n", posFirstQuote);
	break;    	
 	}
	}
        printf("strlen(line2) : %li\n", strlen(line2));
	for (i = posFirstQuote + 1; i < strlen(line2); i++)
        {
        if(line2[i] == '"')
        {
        posLastQuote = i + 1;
        printf ("posLastQuote: %i\n", posLastQuote);
        break;
        }
        }
        int w = 0;
        //printf("lineList[sizeLineList] : %s", lineList[sizeLineList]);
	for (i = posFirstQuote; i < posLastQuote; i++) 
	{
	lineList[sizeLineList][w] = line2[i]; 
        printf("lineList[sizeLineList] %s\n", lineList[sizeLineList]);
        w++;
	}
        //lineList[sizeLineList][w] = "\0";
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
        printf("lineList[2] %s\n ", lineList[sizeLineList]);
	fprintf(fptr2, "%s ", lineList[sizeLineList]);
	}
	// TWOCHAR
	else if (startswith("twoChar", lineList[1])) 
	{
	fprintf(fptr2, "%s ", lineList[0]);
	fprintf(fptr2, "DW ");
        printf("lineList[2] %s\n ", lineList[2]);
	fprintf(fptr2, "%s ", lineList[sizeLineList]);
	}
	// FOURCHAR
        else if (startswith("fourChar", lineList[1]))
	{
	fprintf(fptr2, "%s ", lineList[0]);
	printf("lineList[0] %s\n", lineList[0]);
	fprintf(fptr2, "DD ");
	printf("lineList[2] %s\n ", lineList[sizeLineList]);
	fprintf(fptr2, "%s ", lineList[sizeLineList]);
	}
	fprintf(fptr2, "\n");
	printf("backslash n\n");
	memset(lineList,0,sizeof(lineList));
        }
        printf("%s\n", line);
    }
    fprintf(fptr2, "\n");
    //fprintf(fptr2, "\tret\n");
    fclose(fptr);
    fclose(fptr2);
    return 0;
}


int main(int argc, char* argv[]){
    int i;
    int a;
    if(argc==1)
    {
    printf(BRED "No Extra Command Line Argument Passed Other Than Program Name\n" reset);
    printf(GRN "Do --help to know how to use this cli application\n" reset);
    exit(0);
    }
    else
    {
    printf("%s\n", argv[1]);
    printf("%c\n", argc);
    int similarity_compile;
    char argument[100];
    int filenameFound = 0;
    strcpy(argument, argv[1]);
    char archArg[10];
    char inputFilename[10];
    for (i=ARGUMENT_START;i<argc;i++) 
    {
    printf("argv[%i] : %s\n",i, argv[i]);
    if(strcmp(argv[i], "--arch") == 0)
    {
    printf("arch found\n");
    strcpy(archArg, argv[i+1]);
    printf("archArg : %s\n", archArg);
    i++;
    }
    else if(strcmp(argv[i], "--help") == 0){
    //printf(BLU "USAGE : work in progress, it will be done later\n" reset);
    usage();
    exit(0);
    }
    else {
    strcpy(inputFilename,argv[i]);
    filenameFound = 1;
    printf("filename found\n");
    }
    }
    if (filenameFound == 0){
	printf(BRED "No filename was specified\n" reset);
	exit(0);
    }
    if (argv[1] != NULL){
    //compile(argv[1]);
    compile(inputFilename);
    }
    }
    return 0;
}

