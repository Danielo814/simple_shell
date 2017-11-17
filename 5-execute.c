#include "holberton.h"

void execute(char *arg, char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		perror("fork error");

	if (pid == 0)
	{
		if (execve(arg, args, NULL) == -1)
			perror("execute command failed");
		exit(EXIT_FAILURE);
	}
}
