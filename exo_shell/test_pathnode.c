#include "main.h"

/**
 * main - Test new_PATH_list function
 *
 * Return: Always 0
 */
int main(void)
{
    path_node_t *head, *temp;

    head = new_PATH_list();
    for (temp = head; temp; temp = temp->next)
        printf("%s\n", temp->dir);

    return (0);
}

