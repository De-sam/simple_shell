#include "main.h"

int cmd_set_unset_env(char **argv)
{
	if (strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] != NULL && argv[2] != NULL && argv[3] == NULL)
			set_env_variable(argv[1], argv[2]);

		return (1);
	}
	else if (strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] != NULL && argv[2] == NULL)
			unsetenv(argv[1]);
		return (1);
	}

	return (0);
}
