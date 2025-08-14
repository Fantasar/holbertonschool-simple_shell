#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
    size_t len;

    if (!name || !value || strchr(name, '=') || name[0] == '\0')
    {
        return (-1);
    }
    if (_getenv(name) && !overwrite)
    {
        return (0);
    }

    len = strlen(name) + strlen(value) + 2;
    env_str = malloc(len);
    if (!env_str)
    {
        return (-1);
    }

    sprintf(env_str, "%s=%s", name, value);

    /* putenv garde un pointeur direct, ne pas free(env_str) */
    return (putenv(env_str));
}

