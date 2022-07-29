#include "simple_shell.h"
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
	char *newarg[120] = {NULL, NULL};
	ssize_t nread;
	char *delim = " \n";
	char *line = NULL;
	char *token[120];

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		child = fork();
		if (child == 0)
		{
			token[i] = strtok(line, delim);
			newarg[0] = strdup(token[i]);
			write(1, newarg[0], len);
			while ((token[i] = strtok(NULL, delim)) != NULL)
			{
				strcat(newarg[0], " ");
				strcat(newarg[0], token[i]);
				i++;
			}
			write(1, newarg[0], len);
			if (newarg[0] == NULL)
			{
				free(line);
				line = NULL;
				return (0);
			}
			if (execve(newarg[0], newarg, environ) == -1)
			{
				perror("./shell");
			}

		}
		else
			wait(&status);
	}
	free(line);
	line = NULL;
	return (0);
}
