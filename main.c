#include "main.h"

int main(int argc, char **argv)
{
	string command = NULL;
	(void)argc;

	while (TRUE)
	{
		prompt(&command);
		argv = set_args(command);
		execmd(argv);
	}

	free(argv);
	free(command);

	return (0);
}
