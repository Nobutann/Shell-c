#include <stdio.h>
#include "line.h"
#include "execute.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtins.h"

int main(int argc, char* argv[])
{
    int jobs_list_size = 2;
    Jobs* jobs = (Jobs*)malloc(jobs_list_size * sizeof(Jobs));
    int jobs_number = 0;
    int* jobs_number_ptr = &jobs_number;
    int* jobs_list_size_ptr = &jobs_list_size;

    if (argc == 2)
    {
        FILE* fptr = fopen(argv[1], "r");
        if (fptr == NULL)
        {
            printf("Arquivo não existe.\n");
            return 1;
        }

        while (1)
        {
            char* line = read_file(fptr);
            if (line == NULL || strcmp(line, "exit") == 0)
            {
                return 0;
            }

            bool background = false;
            bool* background_ptr = &background;
            char **args = parse(line, background_ptr);

            if (args[0] == NULL)
            {
                free(args);
                free(line);
                continue;
            }
            
            if (strcmp(args[0], "cd") == 0)
            {
                cd_command(args);
            }
            else if (strcmp(args[0], "fg") == 0)
            {
                fg_command(args, jobs_number_ptr, jobs);
            }
            else
            {
                exec_command(args, background, &jobs, jobs_number_ptr, jobs_list_size_ptr);
            }
            
            free(args);
            free(line);
        }
    }
    else if (argc > 2)
    {
        printf("Quantidade de arquivos inválida.\n");
        return 1;
    }

    while (1)
    {   
        printf("nobushell seq>");
        char *line = read_line();

        if (line == NULL || strcmp(line, "exit") == 0)
        {
            return 0;
        }

        bool background = false;
        bool* background_ptr = &background;
        char **args = parse(line, background_ptr);

        if (args[0] == NULL)
        {
            free(args);
            free(line);
            continue;
        }
        
        if (strcmp(args[0], "cd") == 0)
        {
            cd_command(args);
        }
        else if (strcmp(args[0], "fg") == 0)
        {
            fg_command(args, jobs_number_ptr, jobs);
        }
        else
        {
            exec_command(args, background, &jobs, jobs_number_ptr, jobs_list_size_ptr);
        }
        
        free(args);
        free(line);
    }

    free(jobs);

    return 0;
}