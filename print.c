#include "main.h"

int printChar(char c)
{
	return (write(STDIN_FILENO, &c, 1));
}

int printString(char *str)
{
	int i = 0, count = 0;
	while (str[i])
	{
		count += printChar(str[i++]);
	}

	return (count);
}

void print_environment(void)
{
	extern char **environ;
	int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		printString(environ[i]);
		printChar('\n');
	}
}
