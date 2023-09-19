#include "main.h"
/**
 * set_env_variable - Set an environment variable to a specified value.
 *
 * This function sets an environment variable with the given name (variable)
 * to the provided value. If the operation fails, it prints an error message
 * to the standard error stream.
 *
 * @variable: The name of the environment variable to set.
 * @value: The value to assign to the environment variable.
 */
void set_env_variable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		fprintf(stderr, "Can't set environment variable: %s\n", variable);
	}
}

/**
 * unset_env_variable - Unset (remove) an environment variable.
 *
 * This function unsets (removes) the environment variable with the specified
 * name (variable). If the operation fails, it prints an error message to the
 * standard error stream.
 *
 * @variable: The name of the environment variable to unset.
 */

void unset_env_variable(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "Can't unset environment variable: %s\n", variable);
	}
}
/**
 * change_directory - Change the current working directory.
 *
 * This function changes the current working directory to the specified
 * directory (new_dir). It also updates the environment variables "PWD"
 * to the new directory and "OLDPWD" to the previous working directory.
 * If any of the operations fail, it prints an error message to the
 * standard error stream.
 *
 * @new_dir: The path to the directory to change to.
 */

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
