#include "main.h"
/**
 * tokenize - Breaks a string into tokens using a specified delimiter.
 *
 * This function tokenizes a string by breaking it into smaller
 * substrings separated by a specified delimiter character.
 *
 * @str: The string to tokenize.
 * @delim: The delimiter character used for tokenization.
 *
 * Return: A pointer to the next token in the string, or NULL if no
 *         more tokens are available.
 */
char *tokenize(char *str, const char *delim)
{
	static char *lastToken;
	char *token;

	if (str != NULL)
		lastToken = str;
	if (lastToken == NULL || *lastToken == '\0')
		return (NULL);
	while (*lastToken != '\0' && strchr(delim, *lastToken) != NULL)
		lastToken++;
	if (*lastToken == '\0')
		return (NULL);

	token = lastToken;
	while (*lastToken != '\0' && strchr(delim, *lastToken) == NULL)
		lastToken++;

	if (*lastToken != '\0')
	{
		*lastToken = '\0';
		lastToken++;
	}

	return (token);
}
