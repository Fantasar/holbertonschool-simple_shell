#include "main.h"

/**
 * _setenv - Add or change an environment variable
 * @name: Name of the environment variable
 * @value: Value of the environment variable
 * @overwrite: Flag to indicate if existing variable should be overwritten
 *
 * Return: 0 on success, -1 on failure
 */

int _setenv(const char *name, const char *value, int overwrite)
{
char *env_str;
size_t len = strlen(name) + strlen(value) + 2;

if (!name || !value || strchr(name, '='))
	{
	return (-1);
	}
if (_getenv(name) && !overwrite)
	{
	return (0);
	}

env_str = malloc(len);

if (!env_str)
	{
	return (-1);
	}

sprintf(env_str, "%s=%s", name, value);

return putenv(env_str);

}
