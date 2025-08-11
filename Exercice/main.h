#ifndef MAIN_H
#define MAIN_H

/*==== Header Files ====*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/*===== Prototypes =====*/

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *strtok(char *str, const char *delim);
#endif
