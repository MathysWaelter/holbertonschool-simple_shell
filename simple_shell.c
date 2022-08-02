#include "simple_shell.h"
/**
 * main - creates a shell
 *
 * Return: Always 0
 */
int main(void)
{
	size_t len = 0;
	int status, i;
	pid_t child = 0;
	char **args, **cpyargs;
	ssize_t nread;
	char *delim = " \n", *line = NULL;

	args = calloc(50, sizeof(char *));
	if (!(args))
		exit(98);
	cpyargs = calloc(50, sizeof(char *));
	if (!(cpyargs))
		exit(98);
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		i = 0;
		args[0] = strtok(line, delim);
		i++;
		if (args[0])
		{
			while ((args[i] = strtok(NULL, delim)) != NULL)
				i++;
			for (i = 0; args[i]; i++)
				cpyargs[i] = strdup(args[i]);
			if (_which(&cpyargs) == -1)
			{
				free(cpyargs[0]);
				continue;
			}
			child = fork();
			if (child == 0)
			{
				if (execve(cpyargs[0], cpyargs, environ) == -1)
					perror("./shell");
			}
			else
				wait(&status);
		}
		for (i = 0; cpyargs[i]; i++)
		{
			free(cpyargs[i]);
			cpyargs[i] = NULL;
		}

	}
	free(cpyargs);
	free(args);
	free(line);
	return (0);
}
