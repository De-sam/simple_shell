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
					set_env_variable(argv[1], argv[2]);
			}
			else if (strcmp(argv[0], "unsetenv") == 0)
			{
				if (argv[1] != NULL && argv[2] == NULL)
					unsetenv(argv[1]);
			}
			else if (strcmp(argv[0], "cd") == 0)
			{
				if (argv[1] == NULL || strcmp(argv[1], "~") == 0)
				{
					const char *home_dir = getenv("HOME");
					if (home_dir != NULL)
					{
						change_directory(home_dir);
						for (i = 0; argv[i] != NULL; i++)
							free(argv[i]);
						free(argv);
					}
				}
				else if (strcmp(argv[1], "-") == 0)
				{
					const char *prev_dir = getenv("OLDPWD");
					if (prev_dir != NULL)
					{
						change_directory(prev_dir);
						for (i = 0; argv[i] != NULL; i++)
							free(argv[i]);
						free(argv);
					}
				}
				else
				{
					change_directory(argv[1]);
					for (i = 0; argv[i] != NULL; i++)
						free(argv[i]);
					free(argv);
				}
			}
			else
				execmd(argv);
		}
	}
	

	if(argv != NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv);
	}
	if (command != NULL)
		free(command);
	return (0);
}
