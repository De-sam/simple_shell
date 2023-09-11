#include "main.h"

int printChar(char c)
{
	return (write(1, &c, 1));
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
