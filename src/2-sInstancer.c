#include "holberton.h"

void shellInstance(void)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
		promptShell(), exit(EXIT_SUCCESS);
	else if (pid < 0)
		perror("failed to start shell");
	else
	{

	}
}
