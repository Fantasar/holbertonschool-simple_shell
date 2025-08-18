#include "main.h"

/**
 * main - Simple shell that executes commands given with their full path
 * @void: No arguments are passed to main
 *
 * This program implements a minimal interactive shell.
 * It continuously:
 *   - Displays a prompt ("$ ")
 *   - Reads a line of input from the user
 *   - Parses the command into program name and arguments
 *   - Creates a child process using fork()
 *   - Executes the given program in the child process using execve()
 *   - Waits for the child process to finish before prompting again
 *
 * The shell only accepts commands given with their full path
 * (e.g., "/bin/ls -l"), and uses the current environment variables.
 *
 * Return: Always 0 on success, or 1 on failure.
 */

extern char **environ;

int main(void)
{
char *temp = NULL;
size_t num = 0;
ssize_t len;
pid_t user;
int index = 0;
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

	user = fork();

	if (user == -1)
		{
		perror("fork");
		free(temp);
		continue;
		}

	if (user == 0)
		{
		char *token = strtok(temp, " ");
		while (token != NULL && index < 63)
			{
			argv[index++] = token;
			token = strtok(NULL, " ");
			}
		argv[index] = NULL;
		execve(argv[0], argv, environ);
		perror("execve");
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
