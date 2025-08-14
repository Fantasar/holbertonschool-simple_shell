#include <stdio.h>
#include "main.h"

int main(void)
{
	char *val = _getenv("PATH");

	if (val)
		printf("PATH = %s\n", val);
	else
		printf("PATH not found\n");

	return (0);
}

