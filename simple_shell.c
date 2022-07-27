#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(void)
{
	size_t len = 0;
	char *token = NULL;
	int status;
	pid_t child = 0;
	char **argv = NULL, **env = NULL;

	printf("#Cisfun ");
	while (1)
	{
		char *line = NULL;

		child = fork();
		if (child == 0)
		{
			if (getline(&line, &len, stdin) != -1)
			{
				token = strtok(line, "\n");
				if (execve(token, argv, env) == -1)
				{
					perror("./shell");
					printf("#Cisfun ");
				}

			}
			free(line);
		}
		else
		{
			wait(&status);
		}
	}	return (0);
}
