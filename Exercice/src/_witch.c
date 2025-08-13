#include "main.h"

/**
 * main - Search for a file in the PATH directories
 * @ac: argument count
 * @av: argument values
 *
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **av)
{

char *path_env, *path_copy, *dir;
struct stat st;
char full_path[1024];

if (ac != 2)
	{
	fprintf(stderr, "Usage %s nom_de_fichier\n", av[0]);
	return (1);
	}
path_env = getenv("PATH");
if (!path_env)
	{
	fprintf(stderr, "PATH n'existe pas dans l'environnement\n");
	return (1);
	}

path_copy = strdup(path_env);
if (!path_copy)
	{
	perror("strdup");
	return (1);
	}

dir = strtok(path_copy, ":");

while (dir)
	{
	snprintf(full_path, sizeof(full_path), "%s/%s", dir, av[1]);
	if (stat(full_path, &st) == 0)
		{
		printf("%s\n", full_path);
		}
	dir = strtok(NULL, ":");
	}
free(path_copy);

return(0);
}
