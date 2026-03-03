#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "line.h"

int main(void)
{
    while (1)
    {
        printf("nobu> ");
        char *line = read_line();
        printf("%s", line);
    }

    return 0;
}