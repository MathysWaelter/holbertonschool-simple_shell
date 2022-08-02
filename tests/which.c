#include "simple_shell.h"

int _which(char **arg)
{
	char *path = getenv("PATH");
	char *cmdpath, *token;
	int lenarg, lentok;

	lenarg = strlen(*arg);
	cmdpath = strdup(*arg);
	while ((token = strtok(path, ":")) != NULL)
	{
		lentok = strlen(token);
		if (access(cmdpath, F_OK) == 0)
		{

			printf("INSIDE ACCESS ==> ARG = CMDPATH : %s\n", *arg);
			return (0);
		}
		free(cmdpath);
		cmdpath = malloc(sizeof(char) * (lentok + lenarg + 2));
		cmdpath = strcpy(cmdpath, token);
		cmdpath = strcat(cmdpath, "/");
		cmdpath = strcat(cmdpath, *arg);
		printf("%s\n", cmdpath);
		path = NULL;
	}
	free(cmdpath);
	return (-1);
}
