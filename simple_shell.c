#include "simple_shell.h"
/**
 * fork_wait_execve - creates a child process, exec a command, then leave
 *
 * Return: nothing
 */
void fork_wait_execve(char ***p)
{
	int status;
	pid_t child = 0;

	child = fork();
	if (child == 0)
	{
		if (execve((*p)[0], (*p), environ) == -1)
			perror("./shell");
	}
	else
		wait(&status);
}
/**
 * main - creates a shell
 *
 * Return: Always 0
 */
int main(void)
{
	size_t len = 0;
	int i;
	char **args = calloc(1000, sizeof(char *));
	char **cpyargs = calloc(1000, sizeof(char *));
	ssize_t nread;
	char *delim = " \n", *line = NULL, *linetoNULL;

	if (!(cpyargs) | !(args))
		exit(98);
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		linetoNULL = line;
		for (i = 0; (args[i] = strtok(linetoNULL, delim)) != NULL; i++)
		{
			linetoNULL = NULL;
			cpyargs[i] = strdup(args[i]);
		}
		if (args[0] != NULL)
		{
			if (_which(&cpyargs) == 0)
				fork_wait_execve(&cpyargs);
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
