#include "simple_shell.h"
/**
 * _which - find exec in the path, change strings to get full pathname
 * @args: pointer of pointer to strings
 * @status: pointer of status to change if not found
 * Return: nothing
 */

void _which(char ***args, int *status)
{
	char *path = getenv("PATH"), *copyenv, *cmdpath, *token, *envNULL;
	int i, lenarg, lentok;

	for (i = 0; (*args)[i] && path; i++)
	{
		if (access((*args)[i], F_OK) == 0)
			continue;
		copyenv = strdup(path);
		lenarg = strlen((*args)[i]);
		cmdpath = strdup((*args)[i]);
		envNULL = copyenv;
		while ((token = strtok(envNULL, ":")) != NULL)
		{
			envNULL = NULL;
			lentok = strlen(token);
			free(cmdpath);
			cmdpath = calloc((lentok + lenarg + 2), sizeof(char));
			cmdpath = strcpy(cmdpath, token);
			cmdpath = strcat(cmdpath, "/");
			cmdpath = strcat(cmdpath, (*args)[i]);
			if (access(cmdpath, F_OK) == 0)
			{
				free((*args)[i]);
				(*args)[i] = strdup(cmdpath);
				break;
			}
		}
		free(cmdpath);
		free(copyenv);
	}
	if (access((*args)[0], F_OK) != 0)
	{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, (*args)[0], strlen((*args)[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		*status  = 127;
	}
}
