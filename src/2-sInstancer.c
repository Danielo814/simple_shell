#include "holberton.h"

void shellInstance()
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		promptShell(), exit(1);
	else if (pid < 0)
		perror("failed to start shell");
	else
	{
		wait(NULL);
		shellInstance();
	}
}
