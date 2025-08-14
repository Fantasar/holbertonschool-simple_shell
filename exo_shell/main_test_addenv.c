#include <stdio.h>
#include "main.h"

int main(void)
{
    _setenv("TEST_VAR", "42", 1);
    printf("TEST_VAR=%s\n", _getenv("TEST_VAR"));
    return (0);
}

