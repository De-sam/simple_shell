#include "main.h"

int main(int argc, char **argv)
{
	string command = NULL;
	int i;
	(void)argc;

	while (TRUE)
	{
		prompt(&command);
		if (strcmp(command, "") == 0)
		{
			free(command);
			continue;
		}
		argv = set_args(command);
		if(argv)
		{
			if (strcmp(argv[0], "setenv") == 0)
			{
				if (argv[1] != NULL && argv[2] != NULL && argv[3] == NULL)
				{
					set_env_variable(argv[1], argv[2]);
				}
			}
			else if (strcmp(argv[0], "unsetenv") == 0)
			{
				if (argv[1] != NULL && argv[2] == NULL)
				{
					unsetenv(argv[1]);
				}
			}
			else
			{
				execmd(argv);
			}
		}
	}
	

	if(argv != NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
	if (command != NULL)
	{
		free(command);
	}

	return (0);
}
