#include "main.h"

/**
 * main - Simple shell 0.1
 * Return: 0 on success
 *
 * This shell:
 * - displays a prompt
 * - reads a single command line (no arguments)
 * - executes it only if the full path is provided
 * - handles EOF (Ctrl+D)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_len;
	char *argv[2];

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		read_len = getline(&line, &len, stdin);
		if (read_len == -1)
		{
			printf("\n");
			break;
		}

		line[read_len - 1] = '\0';

		if (line[0] == '\0')
			continue;

		argv[0] = line;
		argv[1] = NULL;

		if (fork() == 0)
		{
			execve(argv[0], argv, environ);
			perror("./shell");
			_exit(1);
		}
		else
		{
			wait(NULL);
		}
	}

	free(line);
	return (0);
}
