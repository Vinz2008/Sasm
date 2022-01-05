#include <stdio.h>
#include <string.h>
#include "startswith.h"
int main() {
    char sample[20] = "print hello";
    int a = startswith("print", sample);
    printf("%i\n", a);
}
