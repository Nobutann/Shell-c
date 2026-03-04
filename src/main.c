#include <stdio.h>
#include "line.h"

int main(void)
{
    while (1)
    {
        printf("nobu> ");
        
        char *line = read_line();
        char **args = parse(line);

        int i = 0;

        printf("%s\n", line);
        printf("%s\n", args[0]);

        while (args[i] != NULL)
        {
            printf("%s\n", args[i]);
            i++;
        }

        free(args);
        free(line);
    }


    return 0;
}