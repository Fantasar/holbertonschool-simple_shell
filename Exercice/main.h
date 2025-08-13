#ifndef MAIN_H
#define MAIN_H

/*==== Header Files ====*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*===== Prototypes =====*/

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *strtok(char *str, const char *delim);
pid_t fork(void);
int execve(const char *pathname, char *const argv[], char *const envp[]);
pid_t wait(int *wstatus);
int fprintf(FILE *stream, const char *format, ... );
char *_getenv(const char *name);
int strncmp(const char *s1, const char *s2, size_t n);
void directory_PATH(char *env);
#endif
