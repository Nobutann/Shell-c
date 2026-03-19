#include <unistd.h>
#include "builtins.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

void cd_command(char** args)
{
    char* home = getenv("HOME");
    char* path = args[1];

    if (path == NULL)
    {
        chdir(home);
        return;
    }

    if (path[0] == '~')
    {
        char* homepath = (char*)malloc(strlen(home) + strlen(path) + 1);
        strcpy(homepath, home);
        strcat(homepath, path + 1);
        chdir(homepath);
        free(homepath);
        return;
    }
    chdir(path);
}

void fg_command(char **args, int* jobs_number, Jobs* jobs)
{
    if (args[1] == NULL)
    {
        printf("Insira o número do processo.\n");
        return;
    }

    int id = atoi(args[1]);

    for (int i = 0; i < *jobs_number; i++)
    {
        if (jobs[i].id == id && jobs[i].active)
        {
            waitpid(jobs[i].pid, NULL, 0);
            jobs[i].active = false;
            return;
        }
    }
}