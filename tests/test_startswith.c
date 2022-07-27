#include "test.h"
#include <stdio.h>
#include <string.h>
#include "../libs/startswith.h"
#include "../libs/color.h"

int test_startswith(){
    char sample[] = "global start";
    printf("sample : %s\n", sample);
    int a = startswith("global", sample);
    int b = startswith("globl", sample);
    printf("A. startswith global (should be 1) : %i\n",a);
    printf("B. startswith globl (should be 0) : %i\n",b);
    if (a == 1 && b == 0) {
        printf(GRN "SUCCESS\n" reset);
        return 1;
    }
    else {
        printf(RED "FAILED\n" reset);
        return 0;
    }
}