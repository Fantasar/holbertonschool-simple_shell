#include "main.h"

/**
 * main - Entry point for string tokenizer example
 *
 * This program asks the user to enter a sentence, reads it from stdin
 * using getline(), and then splits the sentence into separate words
 * using strtok() with a space (" ") as the delimiter.
 * Each word is printed on its own line.
 *
 * Return: Always 0 on success, or -1 on failure.
 */

int main(void)
{
size_t buffer = 0;
char *string = NULL;
ssize_t temp;
char *totem;

printf("Qu'elle phrase est-ce que je dois couper, aujourd'hui ?\n");

temp = getline(&string, &buffer, stdin);

if (temp == -1)
	{
	printf("Erreur: Je retourne dans ma cuisine\n");
	}
else
	{
	totem = strtok(string, " ");
	while (totem != NULL)
		{
		printf("%s\n", totem);
		totem = strtok(NULL, " ");
		}
	printf("Mon travail est fini, je retourne dans la cave de Holberton !\n");
	}
free(string);
return (0);
}
