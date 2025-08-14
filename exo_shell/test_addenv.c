#include <stdio.h>
#include "main.h"

/* Déclaration de tes fonctions */
int _setenv(const char *name, const char *value, int overwrite);
char *_getenv(const char *name);

int main(void)
{
    /* Ajouter une nouvelle variable */
    if (_setenv("MY_VAR", "123", 1) == -1)
    {
        printf("Erreur lors de l'ajout de MY_VAR\n");
        return (1);
    }

    /* Récupérer et afficher la variable */
    printf("MY_VAR = %s\n", _getenv("MY_VAR"));

    /* Modifier la variable */
    if (_setenv("MY_VAR", "456", 1) == -1)
    {
        printf("Erreur lors de la modification de MY_VAR\n");
        return (1);
    }

    printf("MY_VAR après modification = %s\n", _getenv("MY_VAR"));

    /* Essayer d'ajouter sans overwrite */
    if (_setenv("MY_VAR", "789", 0) == -1)
    {
        printf("Erreur lors de l'ajout de MY_VAR sans overwrite\n");
        return (1);
    }

    printf("MY_VAR après tentative sans overwrite = %s\n", _getenv("MY_VAR"));

    return (0);
}

