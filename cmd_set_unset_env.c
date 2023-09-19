#include "main.h"

/**
 * cmd_set_unset_env - Tales in a pointer to a pointer argv
 * @argv: Argument vector
 * Return: Returns an int value
*/
int cmd_set_unset_env(char **argv)
{
	int i;

	if (_str_cmp(argv[0], "setenv") == 0)
	{
		if (argv[1] != NULL && argv[2] != NULL && argv[3] == NULL)
			set_env_variable(argv[1], argv[2]);
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv);

		return (1);
	}
	else if (_str_cmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] != NULL && argv[2] == NULL)
			unsetenv(argv[1]);
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv);
		return (1);
	}

	return (0);
}
