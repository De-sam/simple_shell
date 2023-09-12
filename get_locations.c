#include "main.h"

string get_location(string command)
{
	string path, path_copy, path_token, file_path;
	int command_len, directory_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_len = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_len = strlen(path_token);
			file_path = malloc(command_len + directory_len + 2);

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}

		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}

		return (NULL);
	}

	return (NULL);
}
