#include "main.h"

int prompt(char *prog_name, char **command)
{
	ssize_t n = 0;
	size_t len = 0;
	size_t input_length = 0;
	struct stat buffer;

	if(isatty(0))
		printf("$ ");
	n = getline(command, &len, stdin);
	if (n == EOF)
	{
		free(*command);
		exit(EXIT_SUCCESS);
	}
	
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

	if (!isatty(0))
	{
		if (stat(*command, &buffer) == -1){
			printf("%s: 1: %s: not found", prog_name, *command);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
