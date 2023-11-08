#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * This function implements the main loop of the shell, where it continuously
 * prompts the user for input, reads input, processes commands, and executes
 * them. And handles errors appropriately.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_size;
	int result;

	while (1)
	{
		prompt(); /* display the shell prompt */

		read_size = getline(&input, &input_size, stdin); /* read user input */
		if (read_size == -1)
		{
			free(input);
			return (0); /* exit loop and program on input failure */
		}

		if (input[read_size - 1] == '\n')
			input[read_size - 1] = '\0'; /* remove trailing newline */

		/* Execute the command and handle errors */
		if (read_size > 1)
		{
			result = execute_command(_strtrim(input));
			if (result == -1)
				break;
		}
	}

	free(input);
	return (0);
}
