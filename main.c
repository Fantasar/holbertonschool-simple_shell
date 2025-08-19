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
	char *temp = NULL;
	size_t num = 0;
	ssize_t len;
	pid_t user;
	char *argv[64];

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}
		len = getline(&temp, &num, stdin);

		if (len == -1)
		{
			break;
		}

		temp[strcspn(temp, "\n")] = '\0';

		if (temp[0] == '\0')
			continue;

		user = fork();
		if (user == -1)
		{
			perror("fork");
			continue;
		}
		if (user == 0)
		{
			cut_command(temp, argv);
			execute_command(argv, environ);
			exit(1);
 		}
		else
		{
			wait(NULL);
		}
	}
	free(temp);
	return 0;
}
