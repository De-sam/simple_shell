#include "main.h"

int main(int argc, char **argv)
{
	string command = NULL;
	ssize_t nchar = 0;

	(void)argc;

	while (TRUE)
	{
		nchar = prompt(&command);
		if (nchar EQUALS - 1)
			exit(EXIT_SUCCESS);

		argv = set_args(command);
		execmd(argv);
	}

	free(argv);
	free(command);

	return (0);
}
