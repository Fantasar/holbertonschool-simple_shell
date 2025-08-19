#include "main.h"

/**
* try_exe - Build a full path and attempt to execute a command
* @dir: current directory from PATH
* @argv: array of arguments (command + options)
* @environ: environment variables
* Description: This function builds a possible full path for the given command
* by joining the provided directory and the command name.
* If the resulting path points to an executable file, execve is called.
* If execve fails despite the file being executable, an error is printed
* and the program exits with code 126.
*
* Return: Always 0 if no execution occurs.
* The program exits with:
* - 126 if execve fails after access success
* - 1 if memory allocation fails
*/
int try_exe(char *dir, char *argv[], char **environ)
{
	char *full_path;
	size_t size;

	size = strlen(dir) + strlen(argv[0]) + 2;
	full_path = malloc(size);
	if (!full_path)
	{
		perror("malloc");
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
		exit(126);
	}

	free(full_path);
	return (0);
}

/**
* find_PATH - Search for a command in PATH directories and execute it
* @argv: array of arguments (command + options)
* @environ: environment variables
*
* Description: This function retrieves the PATH environment variable and splits
* it into individual directories. For each directory, it builds a possible full
* path to the command and checks if it is executable. If the command is found,
* execve is called. If the command is not found in any directory, an error
* message is printed and the program exits with code 127.
*
* Return: Nothing (void). The program will exit if the command cannot be found
* or executed.
*/

void find_PATH(char *argv[], char **environ)
{
	char *path, *copy, *dir;

	path = _getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		exit(127);
	}

	copy = strdup(path);
	if (!copy)
	{
		perror("strdup");
		exit(1);
	}

	for (dir = strtok(copy, ":"); dir; dir = strtok(NULL, ":"))
		try_exe(dir, argv, environ);

	fprintf(stderr, "%s: command is not found\n", argv[0]);
	free(copy);
	exit(127);
}
