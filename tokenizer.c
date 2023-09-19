#include "main.h"

char *tokenize(char *str, const char *delim)
{
	static char *lastToken = NULL;
	char *token;

	if (str != NULL)
		lastToken = str;

	if (lastToken == NULL || *lastToken == '\0')
		return NULL;

	while (*lastToken != '\0' && strchr(delim, *lastToken) != NULL)
		lastToken++;

	if (*lastToken == '\0')
		return NULL;

	token = lastToken;
	while (*lastToken != '\0' && strchr(delim, *lastToken) == NULL)
		lastToken++;

	if (*lastToken != '\0')
	{
		*lastToken = '\0';
		lastToken++;
	}

	return token;
}
