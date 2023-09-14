#include "main.h"

void set_env_variable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		fprintf(stderr, "Can't set environment variable: %s\n", variable);
	}
}

void unset_env_variable(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "Can't unset environment variable: %s\n", variable);
	}
}
