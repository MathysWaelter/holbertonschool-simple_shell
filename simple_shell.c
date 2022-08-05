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
void fork_wait_execve(char ***p, int *status)
{
	pid_t child = 0;

	child = fork();
	if (child == 0)
	{
		if (execve((*p)[0], (*p), environ) == -1)
		{
			perror("./shell");
		}
	}
	else
	{
		wait(&(*status));
	}
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
	int status = 0, ex = -1;

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
			ex = is_exit(&cpyargs);
			if (is_env(args[0]) && ex == -1)
			{
				_which(&cpyargs, &status);
				if (status == 0)
					fork_wait_execve(&cpyargs, &status);
			}
		}
		free_loop(&cpyargs);
		if (status != 0 || ex == 0)
			break;
	}
	free(cpyargs);
	free(args);
	free(line);
	exit(status);
}
