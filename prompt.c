#include "main.h"

int prompt(char **command)
{
	ssize_t n = 0;
	size_t len = 0;
	size_t input_length = 0;

	if(isatty(0))
		printf("$ ");
	n = getline(command, &len, stdin);
	if (n == EOF)
	{
		/* Handle EOF command */
		free(*command);
		exit(EXIT_SUCCESS);
	}
	
	/* Remove newline character */
	input_length = strlen(*command);
	if (input_length > 0 && (*command)[input_length - 1] == '\n')
	{
		(*command)[input_length - 1] = '\0';
	}

	if (strcmp(*command, "") == 0)
	{
		free(*command);
		return (0);
	}

	return (1);
}
