#ifndef BUILTINS_H
#define BUILTINS_H

#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int id;
    pid_t pid;
    bool active;
} Jobs;

void cd_command(char** args);
void fg_command(char **args, int* jobs_number, Jobs* jobs);

#endif