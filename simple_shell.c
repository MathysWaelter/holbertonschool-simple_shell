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


	while (1)
	{
		char *line = NULL;


		child = fork();
		if (child == 0)
		{
			printf("#Cisfun ");
			if (getline(&line, &len, stdin) != -1)
			{
				newarg[0] = strtok(line, "\n");
				if (execve(newarg[0], newarg, newenv) == -1)
				{
					perror("./shell");

				}

			}
			free(line);
			return (0);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
