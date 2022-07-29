#include "simple_shell.h"

/**
 * free_s - free strings
 * @args: array of strings
 * @line: buffer containing input line
 */

void free_s(char **args, char *line)
{
	int i = 0;

	free(line);
	line = NULL;
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}

/**
 * main - creates a shell
 *
 * Return: Always 0
 */
int main(void)
{
	size_t len = 0;
	int status, i = 0;
	pid_t child = 0;
	char **args;
	ssize_t nread;
	char *delim = " \n", *line = NULL;

	args = malloc(sizeof(char *) * 10);
	if (!(args))
		exit(98);

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		child = fork();
		if (child == 0)
		{
			args[0] = strtok(line, delim);
			i++;
			while ((args[i] = strtok(NULL, delim)) != NULL)
				i++;
			if (args[0] == NULL)
			{
				free_s(args, line);
				exit(98);
			}
			if (execve(args[0], args, environ) == -1)
				perror("./shell");
		}
		else
			wait(&status);
	}
	free_s(args, line);
	return (0);
}
