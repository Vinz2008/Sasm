#include <stdio.h>
#include "usage.h"
#include "color.h"

int usage(){
    printf(BLU "USAGE\n" reset);
    printf("--help : print this usage page\n");
    return 0;

}
