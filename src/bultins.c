#include <unistd.h>
#include "builtins.h"
#include <stdlib.h>
#include <string.h>

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