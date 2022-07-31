#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char  **list_dir_var_env(char *var_env)
{
	char **dir = malloc(sizeof(char *) * 2);
	char **copydir = malloc(sizeof(char *) * 2);
	char *slash = "/";

	for (int i = 0; (dir[i] = strtok(var_env, ":")) != NULL; i++)
	{
		var_env = NULL;
		dir = realloc(dir, sizeof(char *) * (2 + i));
		copydir = realloc(copydir, sizeof(char *) * (2 + i));
		copydir[i] = malloc(sizeof(char) * strlen(dir[i]) + 2);
		strcpy(copydir[i], dir[i]);
		copydir[i] = strcat(copydir[i], slash);
	}
	return (copydir);
}

int _which(char **args)
{
	char *path = getenv("PATH");
	char **list = list_dir_var_env(path);
	int len;

	for (int i = 0; args[i]; i++)
	{
		for (int j = 0; list[j]; j++)
		{

			list[j] = strcat(list[j], args[i]);
			if (access(list[j], F_OK) == 0)
			{
				len = strlen(list[j]);
				args[i] = malloc(sizeof(char) * (len + 1));
				args[i] = list[j];
				list[j] = NULL;
				break;
			}
		}
	}
	if (access(args[0], F_OK) == -1)
	{
		printf("%s: 1: hbtn_cmd: not found\n", args[0]);
		return (-1);
	}
	return (0);
}
