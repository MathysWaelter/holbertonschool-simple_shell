#include "simple_shell.h"
/**
 * is_env - prints environment variables if env found
 * @arg: arg to check
 * Return: 0 if found, -1 if not or error
 */

int is_env(char *arg)
{
	if (arg && strcmp(arg, "env") == 0)
	{
		printenv();
		return (0);
	}
	return (-1);
}

/**
 * is_exit - if exit found, free arg and return 0
 * @args: pointer to strings to check
 * Return: 0 if found, -1 if not or error
 */
int is_exit(char ***args)
{
	int i;

	if (strcmp((*args)[0], "exit") == 0)
		return (0);
	for (i = 0; (*args)[i] != NULL; i++)
	{
		if (strcmp((*args)[i], "exit") == 0)
		{
			free((*args)[i]);
			(*args)[i] = NULL;
		}
	}
	return (-1);
}
