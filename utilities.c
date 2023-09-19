#include "main.h"

void set_env_variable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		fprintf(stderr, "Can't set environment variable: %s\n", variable);
	}
}

void unset_env_variable(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "Can't unset environment variable: %s\n", variable);
	}
}

void change_directory(const char *new_dir)
{
	char old_dir[PATH_MAX];

	if (getcwd(old_dir, sizeof(old_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}

	if (chdir(new_dir) != 0)
	{
		perror("chdir");
		return;
	}

	if (setenv("PWD", new_dir, 1) != 0)
	{
		perror("setenv");
		return;
	}
	setenv("OLDPWD", old_dir, 1);
}
