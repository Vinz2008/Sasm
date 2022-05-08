#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "assemble.h"
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



int main(int argc, char* argv[]){
    int i;
    int a;
    if(argc==1)
    {
    printf(BRED "ERROR: No Extra Command Line Argument Passed Other Than Program Name\n" reset);
    printf(GRN "Do --help to know how to use this cli application\n" reset);
    exit(0);
    }
    else
    {
    //printf("%s\n", argv[1]);
    //printf("%c\n", argc);
    int similarity_compile;
    char argument[100];
    int filenameFound = 0;
    strcpy(argument, argv[1]);
    char archArg[10];
    char inputFilename[30];
    int IsDebugMode = 0;
    int IsForced = 0;
    char outputFile[15] = "code.asm";
    for (i=ARGUMENT_START;i<argc;i++) 
    {
    //printf("argv[%i] : %s\n",i, argv[i]);
    if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0){
    //printf(BLU "USAGE : work in progress, it will be done later\n" reset);
    usage();
    exit(0);
    }
    /*else if(strcmp(argv[i], "--arch") == 0)
    {
    printf("arch found\n");
    strcpy(archArg, argv[i+1]);
    printf("archArg : %s\n", archArg);
    i++;
    }*/
    else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--debug") == 0) {
            IsDebugMode = 1;
    }
    else if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--force") == 0) {
            IsForced = 1;
    }
    else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0){
    i++;
    strcpy(outputFile, argv[i]);
    }
    else if(startswith("-", argv[i])){
    printf(BRED "ERROR : Invalid option\n" reset);
    printf(BLU "try -h for the list of the options\n" reset);
    exit(0);
    }
    else {
    strcpy(inputFilename,argv[i]);
    filenameFound = 1;
    //printf("filename found\n");
    }
    }
    if (filenameFound == 0){
	printf(BRED "ERROR: No filename was specified\n" reset);
	exit(0);
    }
    if (FileExtensionCmp(inputFilename,"sasm") == 0 && IsForced == 0) {
            printf(BRED "ERROR: filename %s is not a sasm file.\n", inputFilename);
            printf(reset);
            printf("if you want to force the execution of this file, use the -f flag\n");
            exit(0);
    }
    if (argv[1] != NULL){
    //compile(argv[1]);
    assemble(inputFilename, outputFile, IsDebugMode);
    }
    }
    return 0;
}

