#include "main.h"

extern char **environ;

/**
 * _unsetenv - removes an environment variable from the environment
 * @name: name of the variable to remove
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
int i, j;
size_t len;

if (!name || strchr(name, '='))
	{
	return (-1);
	}

len = strlen(name);

for (i = 0; environ[i]; i++)
	{
	if (strncmp(environ[i], name, len) == 0
	    && environ[i][len] == '=')
		{
		free(environ[i]);
		for(j = i; environ[j]; j++=)
			{
			environ[j] = environ[j + 1];
			}
		i--;
		}
	}

return (0);
}
