#include <stdio.h>
#include "line.h"
#include "execute.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    while (1)
    {   
        printf("nobushell>");
        char *line = read_line();
        char **args = parse(line);
        
        if (strcmp(args[0], "cd") == 0)
        {
            cd_command(args);
            
        }
        else
        {
            exec_command(args);
        }
        
        free(args);
        free(line);

    }


    return 0;
}