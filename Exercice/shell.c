#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

int main(void)
{
    char *temp = NULL;
    size_t num = 0;
    ssize_t len;
    pid_t user;

    while (1)
    {
        printf("$ ");
        len = getline(&temp, &num, stdin);

        if (len == -1)
        {
            printf("\n");
            break;
        }

        temp[strcspn(temp, "\n")] = '\0';

        if (temp[0] == '\0')
            continue;

        user = fork();

        if (user == -1)
        {
            perror("fork");
            free(temp);
            return 1;
        }

        if (user == 0)
        {
            char *argv[] = { temp, NULL };
            if (execve(argv[0], argv, environ) == -1)
            {
                perror("execve");
                exit(1);
            }
        }
        else
        {
            wait(NULL);
        }
    }

    free(temp);
    return 0;
}
