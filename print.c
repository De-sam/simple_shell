#include "main.h"

/**
 * printChar - Prints a character to standard output
 * @c: The character to be printed
 *
 * Description:
 * This function prints the given character 'c'
 * to the standard output (stdout).
 *
 * Return: Always returns 1 (the number of characters printed).
 */
int printChar(char c)
{
	return (write(STDIN_FILENO, &c, 1));
}

/**
 * printString - Prints a string to standard output
 * @str: The string to be printed
 *
 * Description:
 * This function prints the given string 'str'
 * to the standard output (stdout).
 *
 * Return: The number of characters printed
 * (excluding the null terminator).
 */
int printString(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		count += printChar(str[i++]);
	}

	return (count);
}

/**
 * print_environment - Prints the environment variables
 * to standard output
 *
 * Description:
 * This function prints the environment variables
 * to the standard output (stdout).
 * It displays each environment variable in the format
 * "VARIABLE=VALUE" on separate lines.
 *
 * Return: No return value.
 */
void print_environment(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printString(environ[i]);
		printChar('\n');
	}
}
