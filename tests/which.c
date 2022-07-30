
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	char *token = NULL;
	char *tmp = NULL;
	int lentok = 0, lenav = 0;
	const char *path = getenv("PATH");
	char *copypath = malloc(sizeof(char) * strlen(path));

	i = 1;

	while (av[i])
	{

		strcpy(copypath, path);
		printf("%s\n", path);
		while (1)
		{
			token  = strtok(copypath, ":");
			if (token == NULL)
			{
				printf("token null\n");
				break;
			}

			lentok = strlen(token);
			lenav = strlen(av[i]);
			tmp = malloc(sizeof(char) * (lentok + lenav) + 2);
			tmp = strcat(tmp, token);
			tmp = strcat(tmp, "/");
			tmp = strcat(tmp, av[i]);


			if (stat(tmp, &st) == 0)
			{
				printf("%s\n", tmp);
				free(copypath);
				copypath = NULL;
				
				break;
			}
			path = NULL;
			free(copypath);
			free(tmp);
			tmp = NULL;
			copypath = NULL;
		}
		i++;
	}
	return (0);
}
