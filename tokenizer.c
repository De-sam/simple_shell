#include "main.h"

char *tokenize(char *str, const char *delim)
{
	static char *lastToken = NULL;
	char *token;

	if (str NEQUAL NULL)
	{
		lastToken = str;
	}

	if (lastToken EQUALS NULL OR *lastToken EQUALS '\0')
	{
		return NULL;
	}

	while (*lastToken NEQUAL '\0' AND strchr(delim, *lastToken) NEQUAL NULL)
	{
		lastToken++;
	}

	if (*lastToken EQUALS '\0')
	{
		return NULL;
	}

	token = lastToken;

	while (*lastToken NEQUAL'\0' AND strchr(delim, *lastToken) EQUALS NULL)
	{
		lastToken++;
	}

	if (*lastToken NEQUAL '\0')
	{
		*lastToken = '\0';
		lastToken++;
	}

	return token;
}

/*
int main() {
    char str[] = "Hello,World,Custom,Strtok";
    const char delim[] = ",";

    char *token = tokenize(str, delim);

    while (token != NULL) {
	printf("Token: %s\n", token);
	token = tokenize(NULL, delim);
    }

    return 0;
}
*/
