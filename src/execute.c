#include "execute.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "builtins.h"
#include <stdio.h>

void exec_command(char** args, bool background, Jobs** jobs, int* jobs_number, int* jobs_list_size)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        execvp(args[0], args);
        perror(args[0]);
        exit(1);
    }
    else if (pid < 0)
    {
        exit(1);
    }
    else
    {   
        if (background)
        {
            if (*jobs_list_size >= 2)
            {
                *jobs_list_size += 2;
                *jobs = (Jobs*)realloc(*jobs, *jobs_list_size * sizeof(Jobs));
            }
            (*jobs)[*jobs_number].id = *jobs_number + 1;
            (*jobs)[*jobs_number].pid = pid;
            (*jobs)[*jobs_number].active = true;
            printf("[%d] %d\n", (*jobs)[*jobs_number].id, pid);

            (*jobs_number)++;

        }
        else
        {
            wait(NULL);
        }
    }
}