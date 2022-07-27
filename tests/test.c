#include "test.h"
#include <stdio.h>
#include <string.h>
#include "../libs/startswith.h"
#include "../libs/color.h"

int main() {
    int i = 0;
    int i2 = 0;
    i++;
    printf(UCYN "%d.STARTSWITH TEST\n" reset, i);
    if (test_startswith() == 1) i2++;
    i++;
    printf(UCYN "%d.REMOVECHARFROMSTRING TEST\n" reset, i);
    if (test_removeCharFromString() == 1) i2++;
    i++;
    printf(UCYN "%d.FILEEXTENSIONCMP TEST\n" reset, i);
    if (test_detect_file_extension() == 1) i2++;
    printf("-------------------\n");
    if (i2 == i){
        printf(BGRN "EVERY TEST SUCCEDED\n" reset);
    } else {
        printf(BRED "SOME TEST FAILED\n" reset);
    }
    printf("-------------------\n");
}
