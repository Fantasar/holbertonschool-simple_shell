#include "main.h"

/**
 * _getenv - retrieves the value of an environment variable
 * @name: the name of the environment variable to search for
 *
 * Return: pointer to the value string if found, NULL otherwise.
 */

char *_getenv(const char *name)
{
	size_t len;
	int index;

	if (name == NULL)
		{
		return (NULL);
		}

	len = strlen(name);

	for (index = 0; environ[index] != NULL; index++)
	{
		if (strncmp(environ[index], name, len) == 0
			&& environ[index][len] == '=')
			{
			return (environ[index] + len + 1);
			}
	}

	return (NULL);
}
