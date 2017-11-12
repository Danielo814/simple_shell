#include "holberton.h"

void promptShell()
{
	char *buffer = NULL;
	char **args;
	size_t bufsize = 0;

	write(STDOUT_FILENO, "SLO.sh:$ ", 9);
	getline(&buffer, &bufsize, stdin);
	getToken(&args, &buffer);
	execute(args);

	free(args);
	free(buffer);
}
