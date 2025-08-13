#include "main.h"

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */

extern char **environ;

int main(int ac, char **av, char **env)
{
(void)ac;
(void)av;

if (env == environ)
	{
	printf("Les deux variables d'environnements sont identiques\n");
	printf("Adresse d'environnements : %p\n", (void*)environ);
	printf("Adresse d'env            : %p\n", (void*)env);
	}
else
	{
	printf("Les variables ne sont pas identiques\n");
	printf("Adresse d'environnements : %p\n", (void*)environ);
	printf("Adresse d'env     : %p\n", (void*)env);
	}
return (0);
}
