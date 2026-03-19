#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

char* read_line(void)
{
    int line_size = 32;
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

    if (c == EOF && i == 0)
    {
        free(line);
        return NULL;
    }

    line[i] = '\0';
    
    return line;
}

char* read_file(FILE* fptr)
{
    int line_size = 32;
    char *line = (char*)malloc(line_size);
    int i = 0;
    int c = fgetc(fptr);

    while (c != EOF && c != '\n')
    {
        line[i] = c;
        i++;
        c = fgetc(fptr);

        if (i >= line_size)
        {
            line_size += line_size;
            line = (char*)realloc(line, line_size);
        }
    }

    if (c == EOF && i == 0)
    {
        free(line);
        return NULL;
    }

    line[i] = '\0';

    return line;
}

char** parse(char *line, bool* background)
{
    int word_limit = 8;
    char** words = (char**)malloc(word_limit * sizeof(char*));
    int i = 0;
    char* word = strtok(line, " ");
    
    while (word != NULL)
    {
        words[i] = word;
        i++;

        if (i >= word_limit)
        {
            word_limit += 2;
            words = (char**)realloc(words, word_limit * sizeof(char*));
        }

        word = strtok(NULL, " ");
    }

    words[i] = NULL;
    
    if (i > 0 && strcmp(words[i - 1], "&") == 0)
    {
        *background = true;
        words[i - 1] = NULL;
    }
    
    return words;
}