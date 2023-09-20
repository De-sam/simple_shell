#include "main.h"

/**
 * get_location - Get the location of a command in PATH
 * @command: command passed
 * Return: Returns a string
*/
string get_location(string command)
{
	string path, path_copy, file_path;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);

		file_path = loc_perser(path_copy, command);
		if (file_path != NULL)
			return (file_path);
		free(file_path);
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (command);

		return (NULL);
	}

	return (NULL);
}

string loc_perser(string path_copy, string command)
{
	string path_token, file_path = NULL;
	int command_len, directory_len;
	struct stat buffer;

	command_len = _str_len(command);
	path_token = tokenize(path_copy, ":");

	while (path_token != NULL)
	{
		directory_len = _str_len(path_token);
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
			path_token = tokenize(NULL, ":");
		}
	}

	return (NULL);
}
