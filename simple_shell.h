#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;
int is_env(char *arg);
int is_exit(char ***args);
void _which(char ***args, int *status);
void fork_wait_execve(char ***p, int *status);
void free_loop(char ***pp);
void printenv(void);
#endif
