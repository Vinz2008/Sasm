#include <string.h>
#include <stdio.h>
#include "startswith.h"

int startswith(char strStartingWith[], char code[]) {
    int similarity;
    int length = strlen(strStartingWith);
    int i;
    for (i = 0; i < length; i++)
    {
        if (strStartingWith[i] == code[i])
        {
            similarity++;
        }
    }
    if (similarity <= length)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
