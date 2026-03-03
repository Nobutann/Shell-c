#include <stdio.h>
#include <stdlib.h>
#include "line.h"

char* read_line(void)
{
    int line_size = 64;
    char *line = (char*)malloc(line_size);
    int i = 0;
    int c = getchar();

    while (c != EOF && c != '\n')
    {
        line[i] = c;
        i++;
        c = getchar();
        
        if (i >= line_size)
        {
            line_size += line_size;
            line = (char*)realloc(line, line_size);
        }
    }

    line[i] = '\n';
    
    return line;
}