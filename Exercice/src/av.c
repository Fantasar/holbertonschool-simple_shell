#include <stdio.h>
#include <unistd.h>

/**
 * main - Print argument in ac.
 *@ac: Numbers of argument.
 *@av: Array for argument.
 * Return: Always 0.
 */

int main(int ac, char **av)
{
int count;

if (av == NULL)
	{
	;
	}
for (count = 0; count <  ac; count++)
	{
	printf("%s\n", av[count]);
	}
return (0);
}

