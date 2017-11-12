#include "holberton.h"

void execute(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		perror("fork error");

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror("execute command failed");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
