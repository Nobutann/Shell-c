#ifndef LINE_H
#define LINE_H

#include <stdbool.h>

char* read_line(void);
char** parse(char *line, bool* background);
char* read_file(FILE* fptr);

#endif