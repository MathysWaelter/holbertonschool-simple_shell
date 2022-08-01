#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	char *args[] = {"echo", "haha", "echo", "/bin/ls", NULL};
	char *pathenv = getenv("PATH");
	char *copyenv;
	char *cmdpath, *token;
	int i, lenarg, lentok;
	char *copyenvorNULL;

	for (i = 0; args[i]; i++)
	{
		copyenv = strdup(pathenv);
		lenarg = strlen(args[i]);
		cmdpath = strdup(args[i]);
		copyenvorNULL = copyenv;
		while ((token = strtok(copyenvorNULL, ":")) != NULL)
		{
			lentok = strlen(token);
			if (access(cmdpath, F_OK) == 0)
			{
				args[i] = cmdpath;
				printf("ARG = CMDPATH : %s\n", args[i]);
				break;
			}
			free(cmdpath);
			cmdpath = malloc(sizeof(char) * (lentok + lenarg + 2));
			cmdpath = strcpy(cmdpath, token);
			cmdpath = strcat(cmdpath, "/");
			cmdpath = strcat(cmdpath, args[i]);
			copyenvorNULL = NULL;
		}
		free(cmdpath);
		free(copyenv);
	}
		return (0);
}
