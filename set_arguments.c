#include "main.h"

char **set_args(char *command)
{
	string command_copy = NULL, token = NULL;
	const char *delim = " \n";
	int i, num_token = 0;
	char **argv = NULL;

	command_copy = strdup(command);
	token = tokenize(command, delim);
	if (strcmp(token, "exit") EQUALS 0)
	{
		/* Handle exit command*/
		free(command_copy);
		free(command);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(token, "env") EQUALS 0)
		print_environment();

	while (token NEQUAL NULL)
	{
		num_token++;
		token = tokenize(NULL, delim);
	}
	num_token++;
	argv = malloc(sizeof(char *) * num_token);
	token = tokenize(command_copy, delim);
	for (i = 0; token NEQUAL NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * sizeof(token));
		strcpy(argv[i], token);
		token = tokenize(NULL, delim);
	}
	argv[i] = NULL;

	free(command_copy);
	return (argv);
}
