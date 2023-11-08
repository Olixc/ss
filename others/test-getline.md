#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

static char input_buffer[BUFFER_SIZE];  /* Static buffer for reading*/
static size_t buffer_pos = 0;           /* Position in the buffer*/
static size_t buffer_size = 0;          /* Number of characters in the buffer*/

char *custom_getline(void) {
    char c, *line = NULL;
    size_t line_size = 0;
    size_t line_length = 0;

    while (1) {
        /* If the buffer is empty, read more data into it*/
        if (buffer_pos >= buffer_size) {
            buffer_size = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
            buffer_pos = 0;

            if (buffer_size <= 0) {
                /* No more data to read or an error occurred*/
                if (line_length == 0) {
                    /* If no input has been read, return NULL to indicate EOF */
                    return NULL;
                } else {
                    /* Otherwise, return the current line*/
                    return line;
                }
            }
        }

        /* Process characters in the buffer*/
        c = input_buffer[buffer_pos++];

        /* If we encounter a newline character, terminate the line and return it*/
        if (c == '\n') {
            if (line_length == 0) {
                /* Handle empty lines (just a newline)*/
               return malloc(1);
            } else {
                line[line_length] = '\0';  /* Null-terminate the line*/
                return line;
            }
        }

        /* If the line buffer is full, resize it*/
        if (line_length + 1 >= line_size) {
            line_size += BUFFER_SIZE;
            line = realloc(line, line_size);
        }

        /*Add the character to the line */
        line[line_length++] = c;
    }
}

int main(void) {
    while (1) {
        char *line = custom_getline();
		int count = strlen(line);
        if (line == NULL) {
            /* End of input, break the loop */
            break;
        }
        printf("You entered: %s\n", line);
		printf("%d\n", count);
        free(line);
		free(count);
    }
    return 0;
}