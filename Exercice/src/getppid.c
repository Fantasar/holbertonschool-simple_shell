#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
pid_t my_pid;
pid_t parent_pid;

my_pid = getpid();
parent_pid = getppid();

printf("PID du processus : %d\n", (int)my_pid);
printf("PID du parent    : %d\n", (int)parent_pid);

return (0);
}
