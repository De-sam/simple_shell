#include "main.h"

/**
 * main - Entry point for a custom shell program
 *
 * Description:
 * This function serves as the entry point for a custom shell program.
 * It initializes variables, continuously prompts the user for input,
 * parses and executes commands, and handles various built-in shell
 * functionalities such as environment variable manipulation and
 * changing the current working directory.
 *
 * @argc: The number of command-line arguments (unused).
 * @argv: An array of strings containing the program name and arguments.
 *
 * Return: Always returns 0 to indicate successful execution.
 */
int main(int argc, char **argv)
{
	string command = NULL, prog_name = NULL;
	int i;

	(void)argc;
	prog_name = argv[0];

	while (TRUE)
	{
		if (!prompt(prog_name, &command))
			continue;
		argv = set_args(command);
		if (argv)
		{
			if (cmd_set_unset_env(argv))
				continue;
			if (cmd_change_directory(argv))
				continue;
			execmd(prog_name, argv);
			if (argv != NULL)
			{
				for (i = 0; argv[i] != NULL; i++)
					free(argv[i]);
				free(argv);
			}
		}
	}

	free(command);
	return (0);
}
