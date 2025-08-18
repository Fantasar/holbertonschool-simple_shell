#include "main.h"

/**
 * main - Simple shell program
 * Return: 0 on success
 *
 * This program shows a prompt, waits for a user command,
 * splits it into arguments, and runs it.
 * It uses fork to create a child process,
 * execve to run the command, and wait to pause
 * until the child finishes.
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
		printf("$ ");
		len = getline(&temp, &num, stdin);
		if (len == -1)
		{
			printf("\n");
			break;
		}
		temp[strcspn(temp, "\n")] = '\0';
		if (temp[0] == '\0')
		continue;
		cut_command(temp, argv);

		if (handle_builtin(argv))
			continue;
		user = fork();
		if (user == -1)
		{
			perror("fork");
			continue;
		}
		if (user == 0)
		{
			execute_command(argv, environ);
			exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
	free(temp);
	return (0);
}
