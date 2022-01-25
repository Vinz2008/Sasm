#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "startswith.h"

int compile(char filetocompile[20]) {
    FILE *fptr;
    FILE *fptr2;
    FILE *fptrtemp;
    char line[20]/*[20]*/;
    fptr = fopen(filetocompile, "r");
    if (fptr == NULL)
    {
        printf("Error! The file is empty\n");   
        exit(1);
    }
    /*fgets(line, "%s", fptr);
    printf("%s", line);*/
    int i;
    fptrtemp = fopen("code.asm", "w");
    fclose(fptrtemp);
    fptr2 = fopen("code.asm", "a");
    while (fgets(line,150, fptr)) {
        /*if (fgets(line,150, fptr) == NULL) break;*/
        i++;
        /*if (strlen("data section") == strlen(line)) {
            printf("true");
        }
        else {
            printf("false");
        }
        printf("%lu\n", strlen("data section"));
        printf("%lu\n", strlen(line));
        printf("%lu\n", strlen("data section\0\n"));
        printf("%c\n", line[13]);
        printf("%c\n", "data section\0"[12]);
        for (i = 0; i <= strlen(line); i++)
        {
        printf("%c\n", line[i]);
        }
        printf("end");
        if ("data section\0\n" == line)
        {
        fprintf(fptr2, "section .data");
        printf("test");
        }
        */
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
	fprintf(fptr2, "\tglobal _start\n _start:\n");
        /*printf("written global _start\n");*/
        }
        else if (startswith("text section", line) == 1)
        {
        fprintf(fptr2, "section .text\n");
        }
        else if (startswith("move", line) || startswith("\tmove", line)) 
        {
        fprintf(fptr2, "\tmov\n");
        } 
        else if (startswith("#", line)) 
        {
        fprintf(fptr2, ";");
        for (i = 1; i < strlen(line) - 1; i++) 
        {
        fprintf(fptr2, "%c", line[i]);
        }
        fprintf(fptr2, "\n");
        }
	/*printf("%i\n",startswith("global start", "line"));*/
        printf("%s\n", line);
    }
    /*printf("%d\n",i);*/
    fprintf(fptr2, "\tret\n");
    fclose(fptr);
    fclose(fptr2);
    return 0;
}


int main(int argc, char* argv[]){
    int i;
    int a;
    printf("%s\n", argv[1]);
    if(argc==1)
    {
    printf("No Extra Command Line Argument Passed OtherThan Program Name");
    exit(0);
    }
    else
    {
    int similarity_compile;
    char argument[100];
    strcpy(argument, argv[1]);
    /*for (i = 0; i < 7; i++)
    {
    if ("compile"[i] == argument[i])
    {
    similarity_compile++;
    }
    }
    if (similarity_compile <= 7)
    {
    compile("test.sasm");
    }*/
    /*
    int similarity_fileExtension;
    char fileExtension[7] = ".sasm";
    int a = strlen(argument);
    int lowerLoopNb1;
    int lowerLoop;
    while (argument[a] != "m"[0])
    {
        lowerLoopNb1++;
        a--;
    }
    lowerLoop = 5 + lowerLoopNb1;
    int loop_fileExtension_min = strlen(argument)-lowerLoop;
    int fileExtension_i = -1 /*strlen(fileExtension)*/;
    /*printf("loop_fileExtension_min: %i\n",loop_fileExtension_min);
    printf("argument: %s\n", argument);
    for (i = strlen(argument) /*+ 1*/ /*; i > loop_fileExtension_min; i--)
    {
        fileExtension_i--;
        printf("argument[%i]: %c\n",i, argument[i]);
        printf("fileExtension[%i]: %c\n", fileExtension_i, fileExtension[i]);
        if (argument[i] == fileExtension[fileExtension_i])
        {
            similarity_fileExtension++;
            printf("i: %i\n", i);
        }
    }
    printf("length: %lu\n", strlen(argument));
    printf("similarity_fileExtension: %i\n", similarity_fileExtension);

    if (similarity_fileExtension >= 5)
    {
        compile(argument);
    }
    else
    {
        printf("The compiler can't compile that file\n");
    }*/
    if (argv[1] != NULL){
    compile(argv[1]);
    }
    /*
    if (argv[1] == "compile")
    {
    compile();
    }
    */
    }
    return 0;
}

