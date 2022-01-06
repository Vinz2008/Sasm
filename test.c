#include <stdio.h>
#include <string.h>
#include "startswith.h"
int main() {
    char sample[20] = "global start";
    int a = startswith("global", sample);
    printf("%i\n", a);
}
