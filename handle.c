#include "main.h"

/**
 * handle_builtin - Execute built-in shell commands
 * @argv: array of command arguments
 *
 * This function checks if the command is a built-in.
 * If the command is "exit", the shell terminates.
 * If the command is "env", it prints all environment variables.
 *
 * Return: 1 if a built-in command was executed, 0 otherwise.
 */

int handle_builtin(char *argv[])
{
	int index;

	if (argv[0] == NULL)
	{
		return (0);
	}

	if (strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}

	if (strcmp(argv[0], "env") == 0)
	{
		for (index = 0; environ[index] != NULL; index++)
		{
			printf("%s\n", environ[index]);
		}
		return (1);
	}

	return (0);
}
