#include "main.h"

int main(int ac, char **argv, char **env)
{
	char *command, *prompt;
	size_t len;

	(void)ac;
	(void)argv;
	(void)env;
	command = NULL;
	prompt = "($) ";
	len = 0;

	printf("%s", prompt);
	getline(&command, &len, stdin);
	printf("%s", command);

	return (0);
}
