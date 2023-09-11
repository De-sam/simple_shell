#include "main.h"

ssize_t prompt(char **command)
{
	ssize_t n;
	size_t len = 0;

	if(isatty(0))
		printf("(Eshell) $ ");
	n = getline(command, &len, stdin);

	if (n == -1)
	{
		return (-1);
	}

	return (n);
}
