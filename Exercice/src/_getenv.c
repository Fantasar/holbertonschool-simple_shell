#include "main.h"

/**
 * _getenv - retrieves the value of an environment variable
 * @name: the name of the environment variable to search for
 *
 * This function loops through the environment variables stored in the
 * global variable `environ`. For each entry, it compares the beginning
 * of the string with the given `name`. If the name matches and the next
 * character is '=', the function returns a pointer to the value part of
 * the environment variable (the string after the '=' sign).
 *
 * Return: pointer to the value string if found, NULL otherwise.
 */

extern char **environ;

char *_getenv(const char *name)
{
char *variable;
int taille;
char next_char;
size_t len;
int index = 0;

if (name == NULL)
	{
	return (NULL);
	}
len = strlen(name);
while (environ[index] != NULL)
	{
	variable = environ[index];
	taille = strncmp(variable, name, len);
	next_char = variable[len];

	if (taille == 0 && next_char == '=')
		{
		return (variable + len + 1);
		}

	index++;
	}
return (NULL);
}
