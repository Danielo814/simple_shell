#include "holberton.h"

void shellInstance()
{
	pid_t pid;
	int status;
	unsigned int stat;

	pid = fork();
	if (pid == -1)
	{
		perror("Error at fork");
		exit(EXIT_FAILURE);
	}
	if(pid == 0)
	{
		stat = shellInstance();
		switch(stat)
		{
			case 1:
			case 2:
			case 4:
			case 5:
			case 6:
				exit (1);
				break;
			case 0:
			case 3:
				exit (0);
				break;
			default:
				exit (1);
		}
	}
	wait(&status);
	stat = WEXITSTATUS(status);
	if (stat)
		promptShell();
	else
		exit(1);
}
