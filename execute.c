#include "main.h"

/**
 * execute_command - Run a command given by the user
 * @argv: array of arguments (command + options)
 * @environ: environment variables
 *
 * This function checks the user command. If the command
 * has a '/' character, it is executed directly with execve.
 * Otherwise, it calls directory_PATH to search for the
 * command inside the PATH directories.
 */

void execute_command(char *argv[], char **environ)
{
	if (argv[0] == NULL)
	{
		return;
	}

	if (strchr(argv[0], '/') != NULL)
	{
		execve(argv[0], argv, environ);
		perror(argv[0]);
		exit(127);
	}
	find_PATH(argv, environ);
	exit(127);
}
