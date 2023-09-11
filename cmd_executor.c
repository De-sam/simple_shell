#include "main.h"

void execmd(char **argv)
{
	string command = NULL, actual_command = NULL;
	pid_t child_pid;

	if (argv)
	{
		command = argv[0];
		actual_command = get_location(command);

		if (actual_command EQUALS NULL)
		{
			perror("Error");
		}
		else
		{
			child_pid = fork();
			if (child_pid EQUALS 0)
			{
				execve(actual_command, argv, NULL);
				perror("Error");
				exit(EXIT_FAILURE);
			}
			else if (child_pid GT 0)
			{
				/* Parent process*/
				/* Wait for the child process to finish*/
				wait(NULL);
				free(actual_command);
			}
			else
			{
				perror("fork error");
			}
		}
	}
}
