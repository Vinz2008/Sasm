#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "assemble.h"
#include "libs/startswith.h"
#include "libs/detect_arch.h"
#include "libs/file.h"
#include "libs/color.h"
#include "libs/usage.h"
#include "emulator.h"

#define ARGUMENT_START 1



int main(int argc, char* argv[]){
    int i;
    if(argc==1){
    printf(BRED "ERROR: No Extra Command Line Argument Passed Other Than Program Name\n" reset);
    printf(GRN "Do --help to know how to use this cli application\n" reset);
    exit(0);
    }
    else {
    char argument[100];
    int filenameFound = 0;
    strcpy(argument, argv[1]);
    //char archArg[10];
    char* inputFilename;
    int IsDebugMode = 0;
    int IsForced = 0;
    int IsNasmMode = 0;
    int IsLdMode = 0;
    int IsEmulating = 0;
    char* outputFile = "code.asm";
    for (i=ARGUMENT_START;i<argc;i++) {
    //printf("argv[%i] : %s\n",i, argv[i]);
    if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0){
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
    outputFile = argv[i];
    }
    else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--nasm") == 0){
        IsNasmMode = 1;
    }
    else if (strcmp(argv[i], "-ld") == 0 || strcmp(argv[i], "--linker") == 0){
        if (IsNasmMode == 0){
                printf("ERROR : you can't run the linker without running nasm\n");
                exit(1);
        }
        IsLdMode = 1;
    }
    else if (strcmp(argv[i], "--emulator") == 0){
        IsEmulating = 1;
    }
    else if(startswith("-", argv[i])){
    printf(BRED "ERROR : Invalid option\n" reset);
    printf(BLU "try -h for the list of the options\n" reset);
    exit(1);
    }
    else {
    inputFilename = argv[i];
    filenameFound = 1;
    }
    }
    if (filenameFound == 0){
	printf(BRED "ERROR: No filename was specified\n" reset);
	exit(1);
    }
    if (FileExtensionCmp(inputFilename,"sasm") == 0 && IsForced == 0) {
        printf(BRED "ERROR: filename %s is not a sasm file.\n", inputFilename);
        printf(reset);
        printf("if you want to force the execution of this file, use the -f flag\n");
        exit(1);
    }
    if (argv[1] != NULL){
    if (IsEmulating == 1){
        init_emulator(inputFilename, outputFile, IsDebugMode);
    } 
    assemble(inputFilename, outputFile, IsDebugMode, IsNasmMode, IsLdMode, IsEmulating);

    }
    }
    return 0;
}

