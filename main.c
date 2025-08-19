#include "main.h"

/**
 * check_user - Handle the result of fork and execute the command
 * @user: PID returned by fork()
 * @argv: array of arguments (command + options)
 * @environ: environment variables
 *
 * Description: This function checks the result of fork().
 * - If fork() fails, it prints an error message and returns.
 * - If in the child process, it calls execute_command() with argv
 *   and environ, and exits with status 1 if execution fails.
 * The parent process is not handled here, it should be managed
 * in the caller (main).
 *
 * Return: Nothing (void).
 */

void check_user(int user, char *argv[], char **environ)
{
	if (user == -1)
	{
		perror("fork");
		return;
	}

	if (user == 0)
	{
		execute_command(argv, environ);
		exit(1);
	}
}

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
			break;
		temp[strcspn(temp, "\n")] = '\0';

		if (temp[0] == '\0')
			continue;

		cut_command(temp, argv);
		if (handle_builtin(argv))
			continue;

		user = fork();
		check_user(user, argv, environ);

		if (user > 0)
			wait(NULL);
	}
	free(temp);
	return (0);
}
