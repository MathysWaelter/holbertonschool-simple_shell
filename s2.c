#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	size_t len = 0;
	int status;
	pid_t child = 0;
	char *newarg[] = {NULL, NULL}, *newenv[] = {NULL};
	char *line = NULL;


	while (1)
	{
		printf("#Cisfun$ ");
		child = fork();
		if (child == 0)
		{
			if ((getline(&line, &len, stdin) != -1))
			{

				newarg[0] = strtok(line, "\n");
				if (execve(newarg[0], newarg, newenv) == -1)
				{
					perror("./shell");
				}
				free(line);
				line = NULL;
				return (0);
			}
		}
		else
			wait(&status);
	}
	return (0);
}
