#include "holberton.h"

char **getToken(char **buf, char *pattern)
{
	int i = 1;
	char *tok;
	char **args;

	tok = strtok(*buf, pattern);
	if (tok == NULL)
		perror("no command passed: "), exit(EXIT_FAILURE);
	args = malloc(sizeof(char *) * 2);
	if (args == NULL)
		perror("Error in Allocation"), exit(EXIT_FAILURE);
	args[0] = tok;

	while (tok != NULL)
	{
		tok = strtok(NULL, pattern);
		if (tok != NULL)
		{
			args = realloc(args, sizeof(char *) * (i + 2));
			if (args == NULL)
			{
				free(buf);
				perror("Error in realloc");
				exit(EXIT_FAILURE);
			}
			args[i] = tok, i++;
		}
	}
	args[i] = NULL;
	return (args);
}
