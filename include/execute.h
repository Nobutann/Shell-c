#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdbool.h>
#include "builtins.h"

void exec_command(char** args, bool background, Jobs** jobs, int* jobs_number, int* jobs_list_size);
void cd_command(char** args);

#endif