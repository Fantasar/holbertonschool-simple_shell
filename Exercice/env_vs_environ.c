#include "main.h"

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */

extern char **environ;

int main(int ac, char **av, char **env)
{

int index = 0;
int temp =0;

while (environ[index] != NULL)
	{
	index++;
	}

while (env[temp] != NULL)
	{
	temp++;
	}

if (environ[3] == env[3])
	{
	printf("Les deux variables d'environnements sont identiques\n");
	printf("%s\n", environ[3]);
	printf("%s\n", env[3]);
	return (1);
	}
else
	{
	printf("Les variables ne sont pas identiques\n");
	printf("%s\n", environ[3]);
	printf("%s\n", env[3]);
	return (0);
	}
return (0);
}
