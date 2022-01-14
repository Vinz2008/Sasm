#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "startswith.h"

int compile() {
    FILE *fptr;
    FILE *fptr2;
    FILE *fptrtemp;
    char line[20]/*[20]*/;
    fptr = fopen("test.sasm", "r");
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
        if (startswith("global start", line) == 1)
        {
	fprintf(fptr2, "\tglobal _start\n");
        /*printf("written global _start\n");*/
        }
	/*printf("%i\n",startswith("global start", "line"));*/
        printf("%s\n", line);
    }
    /*printf("%d\n",i);*/
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
    for (i = 0; i < 7; i++)
    {
    if ("compile"[i] == argument[i])
    {
    similarity_compile++;
    }
    }
    if (similarity_compile <= 7)
    {
    compile();
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
