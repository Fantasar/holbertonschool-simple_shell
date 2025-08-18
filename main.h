#ifndef MAIN_H
#define MAIN_H

/*==== Header Files ====*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/*===== Global environment variable =====*/
extern char **environ;

/*===== Main Prototypes =====*/
char *_getenv(const char *name);
void find_PATH(char *argv[], char **environ);
void execute_command(char *argv[], char **environ);
void cut_command(char *input_user, char *argv[]);

/*===== Larousse Function =====*/

char *strcat(char *dest, const char *src);
char *strtok(char *str, const char *delim);
int strncmp(const char *s1, const char *s2, size_t n);
char *strdup(const char *s);
char *strncpy(char *dest, const char *src, size_t n);
int fprintf(FILE *stream, const char *format, ...);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/*===== Function creating process =====*/
pid_t fork(void);
pid_t wait(int *wstatus);
int execve(const char *pathname, char *const argv[], char *const envp[]);

#endif
