#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(const char *name)
{
	int len = strlen(name);
	for (int i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		return environ[i] + len + 1;
	}
	return NULL;
}

void print_path(void)
{
	char *path = _getenv("PATH");
	if (!path)
	{
		printf("PATH non d√fini\n");
		return;
	}

	char *copy = strdup(path);
	char *token = strtok(copy, ":");

	while (token != NULL)
	
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}

	free(copy);
}

int main(void)
{
	print_path();
	return 0;
}
