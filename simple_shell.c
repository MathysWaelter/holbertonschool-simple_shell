#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
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
	char *newarg[] = {NULL, NULL}, *newenv[] = {NULL};
	char *line = NULL;
	ssize_t nread;


		write(1, "#Cisfun$ ", 9);

		while ((nread = getline(&line, &len, stdin)) != -1)
		{
			child = fork();
			if (child == 0)
			{
				newarg[0] = strtok(line, "\n");
				if (execve(newarg[0], newarg, newenv) == -1)
				{
					perror("./shell");
				}

			}
			else
				free(line);
				wait(&status);

			write(1, "#Cisfun$ ", 9);

		}
	return (0);
}
