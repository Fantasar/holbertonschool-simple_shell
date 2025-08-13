#include "main.h"

/**
 * directory_PATH - Prints each directory in the PATH environment variable
 * @env: Unused parameter (name of the environment variable to get)
 *
 * This function retrieves the PATH environment variable, splits it
 * into individual directories separated by colons (':'), and prints
 * each directory on a new line.
 *
 * Return: Nothing.
 */

extern char **environ;

void directory_PATH(char *env)
{
char *temp_env = NULL;
char *totem = NULL;

if (env == NULL)
	{
	return;
	}
temp_env = _getenv("PATH");

if (temp_env == NULL)
	{
	return;
	}

totem = strtok(temp_env, ":");
while (totem != NULL)
	{
	printf("%s\n", totem);
	totem = strtok(NULL, ":");
	}
}
