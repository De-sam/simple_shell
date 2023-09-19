#include "main.h"
/**
 * cd_home - takes in a pointer to a pointer of char argv
 * @argv: array of vectors
 * Return: This function doesn't return
*/

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

/**
 * cmd_change_directory - This function takes in a pointer to a pointer argv
 * @argv:Another array of vectors
 * Return:Returns an int value
*/
int cmd_change_directory(char **argv)
{
	int i;

	if (str_cmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL || str_cmp(argv[1], "~") == 0)
		{
			cd_home(argv);
			return (1);
		}
		else if (str_cmp(argv[1], "-") == 0)
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
