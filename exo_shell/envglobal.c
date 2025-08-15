#include "main.h"

/**
 * main - prints the environment variables using the global variable environ
 *
 * Return: Always 0.
 */

extern char **environ;

int main(void)
{
	int index = 0;

	while (environ[index] != NULL)
	{
		printf("%s\n", environ[index]);
		index++;
	}
	return (0);
}
