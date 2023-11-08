#include "shell.h"


void handle_exit(char *input, size_t *input_size)
{
    free(input);
    *input_size = 0;
    exit(EXIT_SUCCESS); /* exit the shell gracefully */
}

void handle_cd(char *input, size_t *input_size)
{
    char *path = _strtrim(input + 2); /* Remove 'cd' from the input */
    change_directory(path);
    free(input);
    *input_size = 0;
}