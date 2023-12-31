#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LEN 1024

char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strtrim(char *str);

#endif
