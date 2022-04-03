#include <stdio.h>
#include "usage.h"
#include "color.h"

int usage(){
    printf(BLU "USAGE\n" reset);
    printf("-f, --force : force the compilation of a file which is not a sasm file\n");
    printf("-o, --output : select the output file of the compilation\n");
    printf("-d, --debug : set debug mode on , which is a sort of verbose mode for developping this compiler\n");
    printf("-h, --help : print this usage page\n");
    return 0;

}
