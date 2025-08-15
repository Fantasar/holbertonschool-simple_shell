#include "main.h"
#include <string.h>
#include <stdlib.h>
/**
 * new_PATH_list - Builds a linked list of directories from the PATH variable
 *
 * Return: Pointer to the head of the linked list, or NULL if it fails
 */

path_node_t *new_PATH_list(void)
{
	char *path_copy, *cut;
	path_node_t *head = NULL, *tail = NULL, *temp;

	path_copy = strdup(_getenv("PATH"));
	if (!path_copy)
	return (NULL);

	cut = strtok(path_copy, ":");
	while (cut)
	{
	temp = malloc(sizeof(*temp));
		if (!temp)
		break;
	temp->dir = strdup(cut);
	if (!temp->dir)
	{
		free(temp);
		break;
	}
	temp->next = NULL;
	if (!head)
	head = tail = temp;
	else
	tail = tail->next = temp;
	cut = strtok(NULL, ":");
	}
	free(path_copy);
	return (head);
}

