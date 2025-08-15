#include "main.h"

/**
 * new_PATH_list - Builds a linked list of the directories in the PATH variable
 *
 * This function retrieves the value of the PATH environment variable, duplicates
 * it into a modifiable string, and splits it into individual directory paths
 * using ":" as the delimiter. For each directory found, it creates a new
 * path_node_t node, stores a duplicate of the directory string in it, and links
 * the nodes together to form a singly linked list.
 *
 * Return: A pointer to the head of the linked list containing all directories
 *         from the PATH variable. If PATH is not found or memory allocation
 *         fails, NULL is returned.
 */

extern char **environ;

path_node_t *new_PATH_list(void)
{
	char *len = NULL;
	char *len2;
	char *cut = NULL;
	path_node_t *temp;
	path_node_t *head = NULL;
	path_node_t *tail =NULL;

 	len = _getgenv("PATH");
	if (len == NULL)
	{
		return NULL;
	}
	len2 = strdup(len);
	if (len2 == NULL)
	{
		return (len = NULL);
	}
	cut = strtok(len2, ":");
	while (cut != NULL)
	{
		temp = malloc(sizeof(path_node_t));
		if (temp == NULL)
			{
				free(len2);
				return NULL;
			}
		temp->dir = strdup(cut);
		if (temp->dir == NULL)
		{
			free(temp);
			free(len2);
			return NULL;
		}
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		cut = strtok(NULL, ":");
	}
	free(len2);
	return head;
}
