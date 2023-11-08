#include "shell.h"

/**
 * change_directory - Change the current working directory.
 * @path: The path to the directory to change to.
 *
 * This function changes the current working directory to the provided
 * path. It also updates the environment variables "PWD" and "OLDPWD"
 * accordingly. If no path is provided, the home directory is used.
 * If the path is "-", the previous working directory is used.
 */
void change_directory(char *path)
{
	char *oldpwd = getenv("PWD"); /* get the current working directory */
	char *newpwd; /* to store the new working directory */

	/* If no path provided or an empty path, set path to HOME directory */
	if (path == NULL || strlen(path) == 0)
	{
		path = getenv("HOME");
	}
	/* If path is "-", set path to previous working directory */
	else if (strcmp(path, "-") == 0)
	{
		path = getenv("OLDPWD");
	}

	if (chdir(path) != 0)
	{
		perror("chdir"); /* print error message and return if failed */
		return;
	}
	/* get new working directory path */
	newpwd = getcwd(NULL, 0);
	/* if successfully obtained new path */
	if (newpwd != NULL)
	{
		/* update "OLDPWD" and "PWD" environment variables */
		setenv("OLDPWD", oldpwd, 1);
		setenv("PWD", newpwd, 1);
		free(newpwd);
	}
	else
	{
		perror("getcwd"); /* failed to get new path */
	}
}
