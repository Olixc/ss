#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LEN 1024

int _strlen(char *s);
char *_strtrim(char *str);
void execute_command(char *command);

#endif
