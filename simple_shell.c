#include "main.h"
/**
 * main - creates a shell
 *
 * Return: Always 0
 */

int main(void)
{
	size_t len = 0;
	int status;
	pid_t child = 0;
	char *newarg[] = {NULL, NULL};
	char *line = NULL;
	ssize_t nread;


	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		child = fork();
		if (child == 0)
		{
			newarg[0] = strtok(line, "\n");
			newarg[0] = strtok(line, " ");
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
		{
			wait(&status);
		}
	}
	free(line);
	line = NULL;
	return (0);
}
