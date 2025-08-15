#include <stdio.h>
#include "main.h"

int _unsetenv(const char *name);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite );

int main(void)
{
	_setenv("TEST_VAR", "123", 1);
	printf("Avant : %s\n", _getenv("TEST_VAR"));
	_unsetenv("TEST_VAR");
	printf("Apr√s: %s\n", _getenv("TEST_VAR") ? _getenv("TEST_VAR") : "NULL");
	return 0;
}
