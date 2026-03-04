#include <stdio.h>
#include "line.h"

int main(void)
{
    while (1)
    {
        printf("nobu> ");
        char *line = read_line();
        printf("%s\n", line);
    }

    return 0;
}