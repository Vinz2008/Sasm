#include "test.h"
#include <string.h>
#include <stdio.h>
#include "../libs/removeCharFromString.h"
#include "../libs/color.h"

int test_removeCharFromString(){
    char sample[] = "hello world";
    printf("sample : %s\n", sample);
    removeCharFromString('w', sample);
    printf("should be \"hello orld\" : %s\n", sample);
    if (strcmp("hello orld", sample) == 0) {
        printf(GRN "SUCCESS\n" reset);
        return 1;
    }
    else {
        printf(RED "failed\n" reset);
        return 0;
    }
}