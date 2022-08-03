#include "simple_shell.h"

int _which(char ***args)
{
	char *pathenv = getenv("PATH");
	char *copyenv;
	char *cmdpath, *token;
	int i, lenarg, lentok;
	char *copyenvorNULL;

	if (pathenv == NULL)
		return (-1);

	for (i = 0; (*args)[i]; i++)
	{
		if (access((*args)[i], F_OK) == 0)
			continue;
		copyenv = strdup(pathenv);
		lenarg = strlen((*args)[i]);
		cmdpath = strdup((*args)[i]);
		copyenvorNULL = copyenv;
		while ((token = strtok(copyenvorNULL, ":")) != NULL)
		{
			copyenvorNULL = NULL;
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
		write(STDERR_FILENO, "./hsh: 1: ", 11);
		write(STDERR_FILENO, (*args)[0], strlen((*args)[0]));
		write(STDERR_FILENO, ": not found", 11);
		return (-1);
	}
	return (0);
}
