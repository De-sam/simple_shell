#include "main.h"

int main(int argc, char **argv)
{
	string command = NULL;
	int i;
	(void)argc;

	while (TRUE)
	{
		prompt(&command);
		argv = set_args(command);
		execmd(argv);
	}

	if(argv != NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
	free(command);

	return (0);
}
