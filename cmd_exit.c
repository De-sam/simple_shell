#include "main.h"

/**
 * cmd_exit - Takes in the command and argv arguments
 * @command: Command passed into the function
 * @argv: A array of argument vectors
*/
void cmd_exit(char *command, char **argv)
{
	if (_str_cmp(command, "exit") == 0)
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
