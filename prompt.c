#include "main.h"

ssize_t prompt(char **command)
{
	ssize_t n;
	size_t len = 0;

	if(isatty(0))
		printf("$ ");
	n = getline(command, &len, stdin);
	
	if (n EQUALS -1)
	{
		/* Handle EOF command */
		return (-1);
	}

	return (n);
}
