#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *tokenize(char *str, const char *delim)
{
	static char *lastToken = NULL;
	char *token;

	if (str != NULL)
	{
		lastToken = str;
	}

	if (lastToken == NULL || *lastToken == '\0')
	{
		return NULL;
	}

	while (*lastToken != '\0' && strchr(delim, *lastToken) != NULL)
	{
		lastToken++;
	}

	if (*lastToken == '\0')
	{
		return NULL;
	}

	token = lastToken;

	while (*lastToken != '\0' && strchr(delim, *lastToken) == NULL)
	{
		lastToken++;
	}

	if (*lastToken != '\0')
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
