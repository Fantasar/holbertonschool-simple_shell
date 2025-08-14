#include "main.h"

/**
 * main - Entry point for the simple getline example
 *
 * This program displays a prompt "$ ", waits for user input,
 * reads a full line from stdin using getline(), and then
 * prints back the line entered by the user.
 *
 * Return: Always 0 on success, or -1 on failure.
 */

int main(void)
{
size_t buffer = 0;
char *string = NULL;
ssize_t temp;

printf("$ ");
temp = getline(&string, &buffer, stdin);

if (temp == -1)
	{
	printf("\n");
	}
else
	{
	printf("%s", string);
	}
free(string);
return (0);
}
