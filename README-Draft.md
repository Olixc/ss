<img src="https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg" alt="Haylix_Shell" width="1000">

# ALX - Simple Shell Team Project
This is an ALX collaboration project on Shell. We were tasked to create a simple shell that mimics the Bash shell. Code a simple shell for [ALX SE Program](https://www.alxafrica.com/software-engineering-plus/). This assignment incorporates all topics covered so far, and marks the conclusion of the section of the course that is strictly about learning C programming.

### Prerequisites
Only use the following functions and system calls:
```
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
```

## General Requirement for project

- All files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/alx-tools/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/alx-tools/Betty/blob/master/betty-doc.pl)
- Shell should not have any memory leaks
- No more than 5 functions per file
- All header files should be include guarded
- Write a `README` with the description of the project
- You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository. Format, see [Docker](https://github.com/moby/moby/blob/master/AUTHORS).

### Synopsis
This repository holds all the code necessary for our custom simple shell to run. Our shell should handle the executions of executables found in the environmental variable PATH, with or without their full paths. Sample commands that our shell supports include `ls` (`/bin/ls`), `pwd`, `echo`, `which`, `whereis`, etc.

### Compilation
Compile like this:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
And execute with:
```
./hsh
```
Or (to track memory errors)

```
valgrind ./hsh
```

## Usage
After compilation, running the executable should look like this:
```
vagrant@olix:simple_shell $ ./hsh
#cisfun$ cat shell.h
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
int _strcmp(const char *s1, const char *s2);
int _strlen(char *s);

#endif /* SHELL_H */

#cisfun$ exit 
vagrant@olix:simple_shell$ 
```

## Description of File Structure
### <div align="center">TASK 1</div>
1. [shell.h](shell.h) - Header file:
	* Will contain all macros, standard library include-guards, struct definitions, and function prototypes.
2. [main.c](main.c) - Entry point of the custom shell program:
	* `main()` - function implements an interactive shell that repeatedly prompts the user for input, executes the entered command, and handles errors and termination.
	* `execute_command()` - contains the execute_command function that checks if the command (user's input) is executable before attempting to execute. And handle errors appropriately.
3. [string_format.c](string_format.c) - Utility function that deals with trimming leading and trailing whitespace from a string:
	* `_strtrim()` -  function trims leading and trailing whitespace characters (space, tab, and newline) from the given string.
---
### <div align="center">TASK 2</div>
1. [shell.h](shell.h) - Header file:
	* Will contain all macros, standard library include-guards, struct definitions, and function prototypes.
2. [main.c](main.c) - Entry point to the custom shell program:
	* `main()` - function implements an interactive shell that repeatedly prompts the user for input, executes the entered command, and handles errors and termination.
	* `execute_command()` - contains the execute_command function that executes a shell command by forking a new process and uses execve to execute the given command along with its arguments. And handle errors appropriately.
3. [string_format.c](string_format.c) - Utility function that deals with trimming leading and trailing whitespace from a string:
	* `_strtrim()` -  function trims leading and trailing whitespace characters (space, tab, and newline) from the given string.
4. [string_functions.c](string_functions.c) - Includes all utility functions that deal with string operations:
	* `_strlen()` - Returns the length of a string. Recreation of `strlen()` from `<string.h>`
	* `_strlen_const()` - Calculates the length of a null-terminated string.
	* `_strdup()` - Creates a duplicate of the input string. Recreation of `strdup()` from `<string.h>`
	* `_strcat()` - concatenate two strings.
	* `_strcmp()` - compares two strings.
---
### <div align="center">TASK 3</div>
1. [shell.h](shell.h) - Header file:
	* Will contain all macros, standard library include-guards, struct definitions, and function prototypes.
2. [main.c](main.c) - Entry point to the custom shell program:
	* `main()` - function implements an interactive shell that repeatedly prompts the user for input, executes the entered command, and handles errors and termination.
3. [prompt.c](prompt.c) - Function to display the shell prompt:
	* `prompt()` - function displays the shell prompt ('$ ') to the standard output if the input is being read from a terminal.
4. [string_format.c](string_format.c) - Utility function that deals with trimming leading and trailing whitespace from a string:
	* `_strtrim()` -  function trims leading and trailing whitespace characters (space, tab, and newline) from the given string.
5. [execute.c](execute.c) - Includes the function that is essential to the core functionality. Fork and Child Process executor:
	* `execute_command()` - contains the execute_command function that executes a shell command by forking a new process and uses execve to execute the given command with arguments. It tokenizes the command_with_args to extract individual arguments and then calls execute_child_process to handle the execution.
	* `execute_child_process()` - this function is called by the child process to execute the specified command with the given arguments using execve. It looks up the command in the PATH and handles errors appropriately.
6. [get_path.c](get_path.c) - Path finder function:
	* `get_path()` - gets the full path of a command by searching the PATH. And returns a dynamically allocated string containing the full path of the command if found and executable, otherwise NULL.
7. [getenv.c](getenv.c) - Environment variable function:
	* `getenv()` - function that gets the value of an environment variable by searching through the environment variables and returns the pointer to the value of the environment variable if found, otherwise NULL.
8. [string_functions.c](string_functions.c) - Includes all utility functions that deal with string operations:
	* `_strlen()` - Returns the length of a string. Recreation of `strlen()` from `<string.h>`
	* `_strlen_const()` - Calculates the length of a null-terminated string.
	* `_strdup()` - Creates a duplicate of the input string. Recreation of `strdup()` from `<string.h>`
	* `_strcat()` - concatenate two strings.
	* `_strcmp()` - compares two strings.
9. [string_operations_2.c](string_operations_2.c) - Additional file that includes all utility functions that deal with string operations:
	* `_strcpy()` - copies the string pointed to by src including the terminating null byte `\0` to the buffer pointed to by dest.
	* `_strncpy()` - same thing as strcpy, but copies strings to a certain nth byte.
	* `_strncmp()` - compares two strings and returns their difference.
---
### <div align="center">TASK 4</div>
1. [shell.h](shell.h) - Header file:
	* Will contain all macros, standard library include-guards, struct definitions, and function prototypes.
2. [main.c](main.c) - Entry point to the custom shell program:
	* `main()` - function implements an interactive shell that repeatedly prompts the user for input, executes the entered command, handles the "exit" command and handles errors and termination.
3. [prompt.c](prompt.c) - Function to display the shell prompt:
	* `prompt()` - function displays the shell prompt ('$ ') to the standard output if the input is being read from a terminal.
4. [string_format.c](string_format.c) - Utility function that deals with trimming leading and trailing whitespace from a string:
	* `_strtrim()` -  function trims leading and trailing whitespace characters (space, tab, and newline) from the given string.
5. [execute.c](execute.c) - Includes the function that is essential to the core functionality. Fork and Child Process executor:
	* `execute_command()` - contains the execute_command function that executes a shell command by forking a new process and uses execve to execute the given command with arguments. It tokenizes the command_with_args to extract individual arguments and then calls execute_child_process to handle the execution.
	* `execute_child_process()` - this function is called by the child process to execute the specified command with the given arguments using execve. It looks up the command in the PATH and handles errors appropriately.
6. [get_path.c](get_path.c) - Path finder function:
	* `get_path()` - gets the full path of a command by searching the PATH. And returns a dynamically allocated string containing the full path of the command if found and executable, otherwise NULL.
7. [getenv.c](getenv.c) - Environment variable function:
	* `getenv()` - function that gets the value of an environment variable by searching through the environment variables and returns the pointer to the value of the environment variable if found, otherwise NULL.
8. [string_functions.c](string_functions.c) - Includes all utility functions that deal with string operations:
	* `_strlen()` - Returns the length of a string. Recreation of `strlen()` from `<string.h>`
	* `_strlen_const()` - Calculates the length of a null-terminated string.
	* `_strdup()` - Creates a duplicate of the input string. Recreation of `strdup()` from `<string.h>`
	* `_strcat()` - concatenate two strings.
	* `_strcmp()` - compares two strings.
9. [string_operations_2.c](string_operations_2.c) - Additional file that includes all utility functions that deal with string operations:
	* `_strcpy()` - copies the string pointed to by src including the terminating null byte `\0` to the buffer pointed to by dest.
	* `_strncpy()` - same thing as strcpy, but copies strings to a certain nth byte.
	* `_strncmp()` - compares two strings and returns their difference.
---
### <div align="center">TASK 5</div>
1. [shell.h](shell.h) - Header file:
	* Will contain all macros, standard library include-guards, struct definitions, and function prototypes.
2. [main.c](main.c) - Entry point to the custom shell program:
	* `main()` - function implements an interactive shell that repeatedly prompts the user for input, executes the entered command, handles the "exit" and "env" commands and handles errors and termination.
3. [prompt.c](prompt.c) - Function to display the shell prompt:
	* `prompt()` - function displays the shell prompt ('$ ') to the standard output if the input is being read from a terminal.
4. [string_format.c](string_format.c) - Utility function that deals with trimming leading and trailing whitespace from a string:
	* `_strtrim()` -  function trims leading and trailing whitespace characters (space, tab, and newline) from the given string.
5. [execute.c](execute.c) - Includes the function that is essential to the core functionality. Fork and Child Process executor:
	* `execute_command()` - contains the execute_command function that executes a shell command by forking a new process and uses execve to execute the given command with arguments. It tokenizes the command_with_args to extract individual arguments and then calls execute_child_process to handle the execution.
	* `execute_child_process()` - this function is called by the child process to execute the specified command with the given arguments using execve. It looks up the command in the PATH and handles errors appropriately.
6. [get_path.c](get_path.c) - Path finder function:
	* `get_path()` - gets the full path of a command by searching the PATH. And returns a dynamically allocated string containing the full path of the command if found and executable, otherwise NULL.
7. [getenv.c](getenv.c) - Environment variable function:
	* `getenv()` - function that gets the value of an environment variable by searching through the environment variables and returns the pointer to the value of the environment variable if found, otherwise NULL.
8. [environments.c](environments.c) - Print envrionment variables.
	* `print_environment()` - this function prints the environment variables to the standard output, with each variable followed by a newline character.
9. [string_functions.c](string_functions.c) - Includes all utility functions that deal with string operations:
	* `_strlen()` - Returns the length of a string. Recreation of `strlen()` from `<string.h>`
	* `_strlen_const()` - Calculates the length of a null-terminated string.
	* `_strdup()` - Creates a duplicate of the input string. Recreation of `strdup()` from `<string.h>`
	* `_strcat()` - concatenate two strings.
	* `_strcmp()` - compares two strings.
10. [string_operations_2.c](string_operations_2.c) - Additional file that includes all utility functions that deal with string operations:
	* `_strcpy()` - copies the string pointed to by src including the terminating null byte `\0` to the buffer pointed to by dest.
	* `_strncpy()` - same thing as strcpy, but copies strings to a certain nth byte.
	* `_strncmp()` - compares two strings and returns their difference.
11. [AUTHORS](AUTHORS) - List of contributors.
---

## TODO
Completed tasks are checked with an (`X`).
---
### Mandatory
- [] Display prompt repeatedly and await user's input. Handle errors if executable cannot be found. Handle the EOF condition (`Ctrl-D`).
- [] Handle command lines with arguments. (`/bin/ls -l`)
- [] Handle path. Fork must not be called if the command doesn't exist.
- [] Build env function

### Advanced

#### Recreating standard library functions
- [ ] getline = write your own getline function.
- [ ] strtok = strtok is prohibited. Create your own custom function.
- [ ] `exit` handles arguments to exit
- [ ] setenv = Implement the setenv and unsetenv builtin commands
- [ ] unsetenv
- [ ] getenv

#### Handling Operators, Seperators, Variables and Comments
- [ ] Handle ``;``
- [ ] Handle ``&&``, and ``||``
- [ ] Catch ``^C`` (CTRL + C) -- Find the signal and change its behavior.
- [ ] Handle ``#`` Comments


#### Implementing Shell Builtins
- [ ] register builtins before executing commands
- [ ] cd
- [ ] alias
- [ ] help
- [ ] history
- [ ] Deal with variables
- [ ] Scripts as input


## Authors
* **Abdulrasaq Noibi** [LinkedIn](https://www.linkedin.com/in/olix/) || [Twitter](https://twitter.com/Olixpin)
* **Ayomide Kayode** [LinkedIn](https://www.linkedin.com/in/ayomide-kayode-b24a22277/) || [Twitter](https://twitter.com/kazzy_wiz)
