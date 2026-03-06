#include "execute.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void exec_command(char** args)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        execvp(args[0], args);
    }
    else if (pid < 0)
    {
        exit(1);
    }
    else
    {
        wait(NULL);
    }
}
