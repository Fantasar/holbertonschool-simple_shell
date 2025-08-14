#include <stdio.h>
#include "main.h"

/* Example main to test the function */
int main(void)
{
	char *value = _getenv("PATH");

	if (value)
		printf("PATH = %s\n", value);
	else
		printf("PATH not found\n");

	return (0);
}
