#include "main.h"

void cmd_exit(char *command, char **argv)
{
	if (strcmp(command, "exit") == 0)
	{
		int status = 0;
		if (argv[1] != NULL)
		{
			status = atoi(argv[1]);
		}

		free(command);
		free(argv);
		exit(status);
	}
}
