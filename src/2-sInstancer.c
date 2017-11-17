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
		stat = promptShell();
		switch(stat)
		{
			case 6:
				exit (1);
				break;
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
	        shellInstance();
       else
	        return;
}
