#include "simple_shell.h"
/**
 * free_loop - free the strings of a pointer of strings
 *
 * Return: nothing
 */
void free_loop(char ***pp)
{
	int i;

	for (i = 0; (*pp)[i]; i++)
	{
		free((*pp)[i]);
		(*pp)[i] = NULL;
	}
}
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
	int status = 0;

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
		if (strcmp(cpyargs[0], "exit") == 0)
		{
			free_loop(&cpyargs);
			break;
		}
		if (args[0] != NULL)
		{
			status = _which(&cpyargs);
			if (status == 0)
				fork_wait_execve(&cpyargs);
		}
		free_loop(&cpyargs);
		if (status != 0)
			break;
	}
	free(cpyargs);
	free(args);
	free(line);
	if (status != 0)
		exit(status);
	return (0);
}
