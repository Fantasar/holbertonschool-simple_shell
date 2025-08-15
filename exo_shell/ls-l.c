#include "main.h"

int main(void)
{
	int count = 0;
	pid_t enfant;

	while (count <= 5)
	{
	enfant = fork();

	{
		if (enfant == -1)
		perror("fork");
		return (1);
	}

	{
	if (enfant == 0)
	{
		char *args [] = { "ls", "-l", "/tmp", NULL };
		execve("/bin/ls", args, environ);

		perror("execve");
		return (1);
	}
	else
		{
			wait(NULL);
			count++;
		}
	}

	return (0);
}
