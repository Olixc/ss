#include "shell.h"

/**
 * execute_command - Execute a command with arguments in a child process.
 * @command_with_args: The command with its arguments.
 *
 * This function forks a child process to execute the given command along with
 * its arguments using the execve system call. It handles errors related to
 * forking, executing the command, and accessing the command's executable file.
 */
void execute_command(char *command_with_args)
{
	pid_t child_pid;
	int status, arg_count = 0;
	char *token, *args[MAX_INPUT_LEN / 2 + 2];

	/* fork a child process */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return;
	}
	if (child_pid == 0) /* child process */
	{
		/* tokenize commands and its arguments */
		token = strtok(command_with_args, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		/* check if command is executable */
		if (access(args[0], X_OK) == 0)
		{
			/* execute the command */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				_exit(EXIT_FAILURE); /* exit child process with failure */
			}
		}
		else
		{
			perror("./shell "); /* print error message */
			_exit(EXIT_FAILURE); /* exit child process with success status */
		}
	}
	else
		wait(&status); /* wait for child process to complete */
}

/**
 * main - Entry point of the custom shell program.
 *
 * This function implements an interactive shell that repeatedly prompts
 * the user for input, executes the entered command,
 * and handles errors and termination.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_size;

	while (1)
	{
		/* check if the input is from a terminal and display the prompt */
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
			fflush(stdout); /* flush the output buffer */
		}
		/* read user input */
		read_size = getline(&input, &input_size, stdin);
		if (read_size == -1)
		{
			free(input); /* free allocated memory */
			return (0);	 /* exit the shell */
		}
		/* Remove the newline character at the end of input if found*/
		if (input[read_size - 1] == '\n')
		{
			input[read_size - 1] = '\0';
		}
		/* check if the input is not empty and execute the command */
		if (read_size > 1)
			execute_command(_strtrim(input)); /* Execute the command */
	}
	free(input); /* free allocated memory */
	return (0);	 /* exit the shell */
}
