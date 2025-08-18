#include "main.h"

/**
 * find_PATH - Search and run a command from PATH.
 * @argv: array of arguments (command + options).
 * @environ: environment variables.
 *
 * This function gets the PATH variable and splits it into
 * directories. For each directory, it builds a possible
 * full path to the command. If the command is found and
 * can be executed, execve is called. If no match is found,
 * it prints an error "command not found".
 */

void find_PATH(char *argv[], char **environ)
{
	char *path = _getenv("PATH");
	char *copy = strdup(path);
	char *dir = strtok(copy, ":");

	while (dir != NULL)
	{
		size_t size = strlen(dir) + strlen(argv[0]) + 2;
		char *full_path = malloc(size);

		if (full_path == NULL)
		{
			perror("malloc");
			free(copy);
			exit(1);
		}

		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, argv[0]);

		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, argv, environ);
			perror("execve");
			free(full_path);
			free(copy);
			exit(1);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	fprintf(stderr, "%s: command not found\n", argv[0]);
	free(copy);
}
