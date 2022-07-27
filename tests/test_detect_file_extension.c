#include "test.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libs/detect_file_extension.h"
#include "../libs/color.h"

int test_detect_file_extension(){
    char sample[] = "test.asm";
    int output = FileExtensionCmp("test.asm", "asm");
    printf("verify if test.asm is an asm file (should be 1) : %d\n", output);
    if (output == 1) {
        printf(GRN "SUCCESS\n" reset);
        return 1;
    }
    else {
        printf(RED "failed\n" reset);
        return 0;
    }
}