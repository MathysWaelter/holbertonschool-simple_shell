#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	(void)argc;
	pid_t child_pid;
	int status;

	while (1)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			size_t len = 0;
			char *line = NULL;


			printf("#cisfun$ ");
			getline(&line, &len, stdin);
			printf("%s", line);
			argv[0] = line;
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				printf("ERRRRROOOOORRRR\n");
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
