#include "main.h"

void prompt(char **command)
{
	ssize_t n;
	size_t len = 0;
	size_t input_length;

	if(isatty(0))
		printf("$ ");
	n = getline(command, &len, stdin);
	if (n == -1)
	{
		/* Handle EOF command */
		free(*command);
		exit(EXIT_SUCCESS);
	}

	/*Remove newline character*/
	input_length = strlen(*command);
	if (input_length > 0 && (*command)[input_length - 1] == '\n')
	{
		(*command)[input_length - 1] = '\0';
	}
}
