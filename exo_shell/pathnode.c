#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * new_PATH_list - Builds a linked list of the directories in the PATH variable
 *
 * Return: A pointer to the head of the linked list, or NULL on failure.
 */
extern char **environ;

path_node_t *new_PATH_list(void)
{
    char *path_value;
    char *path_copy;
    char *cut;
    path_node_t *temp;
    path_node_t *head = NULL;
    path_node_t *tail = NULL;

    path_value = _getenv("PATH");
    if (path_value == NULL)
        return (NULL);

    path_copy = strdup(path_value);
    if (path_copy == NULL)
        return (NULL);

    cut = strtok(path_copy, ":");
    while (cut != NULL)
    {
        temp = malloc(sizeof(path_node_t));
        if (temp == NULL)
        {
            free(path_copy);
            return (NULL);
        }
        temp->dir = strdup(cut);
        if (temp->dir == NULL)
        {
            free(temp);
            free(path_copy);
            return (NULL);
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

    free(path_copy);
    return (head);
}

