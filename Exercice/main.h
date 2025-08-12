#ifndef MAIN_H
#define MAIN_H

/*==== Header Files ====*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*===== Prototypes =====*/

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *strtok(char *str, const char *delim);
pid_t fork(void);
int execve(const char *pathname, char *const argv[], char *const envp[]);
pid_t wait(int *wstatus);
#endif
