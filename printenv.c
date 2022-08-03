#include "simple_shell.h"
/*
 * printenv - print all environment variables and their content
 *
 * Return: nothing
 */
void printenv()
{
	int i = 0;

	while (environ[i] != NULL)
	{
		puts(environ[i]);
		i++;
	}
}
