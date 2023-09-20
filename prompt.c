#include "main.h"

/**
 * prompt - Display a command prompt and read user input
 *
 * Description:
 * This function displays a command prompt when input is coming from a terminal
 * and reads the user's input from the standard input also storing the user's
 * input in the memory pointed to by @command and performs various checks and
 * adjustments, such as removing trailing newline characters and handling
 * empty input.
 *
 * @command: A pointer to a string where the user's input will be stored.
 * Return: 1 if user input is valid and not empty, 0 otherwise.
 */
int prompt(char **command)
{
	ssize_t n = 0;
	size_t len = 0;
	size_t input_length = 0;

	if (isatty(0))
		printf("$ ");
	n = getline(command, &len, stdin);
	if (n == EOF)
	{
		free(*command);
		exit(EXIT_SUCCESS);
	}

	input_length = _str_len(*command);
	if (input_length > 0 && (*command)[input_length - 1] == '\n')
	{
		(*command)[input_length - 1] = '\0';
	}

	if (_str_cmp(*command, "") == 0)
	{
		free(*command);
		return (0);
	}

	return (1);
}
