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
	free(dir);
	dir = NULL;
	return (copydir);
}

int main(void)
{
	char *args[] = {"ls", "haha", "bin/ls", NULL};
	char *path = getenv("PATH");
	char **list = list_dir_var_env(path);
	int lenlist, lenarg;

	for (int i = 0; args[i]; i++)
	{
		lenarg = strlen(args[i]);
		for (int j = 0; list[j]; j++)
		{
			lenlist = strlen(list[j]);
			list[j] = realloc(list[j], lenlist + lenarg + 1);
			list[j] = strcat(list[j], args[i]);
			if (access(list[j], F_OK) == 0)
			{
				args[i] = list[j];
				list[j] = NULL;
				break;
			}
			puts(args[0]);
			puts(args[i]);
		}
	}
	if (access(args[0], F_OK) == -1)
	{
		printf("%s not found...\n", args[0]);
		return (-1);
	}
	return (0);
}
