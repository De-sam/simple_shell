#include "main.h"

void cd_home(char **argv)
{
	const char *home_dir = getenv("HOME");
	int i;

	if (home_dir != NULL)
	{
		change_directory(home_dir);
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv);
	}
}

int cmd_change_directory(char **argv)
{
	int i;

	if (strcmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL || strcmp(argv[1], "~") == 0)
		{
			cd_home(argv);
			return (1);
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
			return (1);
		}
		else
		{
			change_directory(argv[1]);
			for (i = 0; argv[i] != NULL; i++)
				free(argv[i]);
			free(argv);
			return (1);
		}
	}
	return (0);
}
