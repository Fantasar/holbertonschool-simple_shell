#include "main.h"

/**
 * cut_command - Split user input into arguments.
 * @input_user: string entered by the user.
 * @argv: array to store the arguments.
 *
 * This function takes the user input string and
 * separates it by spaces. Each word becomes one
 * argument in the argv array. The array ends with
 * NULL to prepare it for execve.
 */

void cut_command(char *input_user, char *argv[])
{
	int index = 0;
	char *token = strtok(input_user, " ");

	while (token != NULL && index < 63)
	{
		argv[index++] = token;
		token = strtok(NULL, " ");
	}

	argv[index] = NULL;
}
