#include "holberton.h"

char **getToken(char **buf, char *pattern)
{
	int i = 1;
	char *tok;
	char **args;
	unsigned int Tokcount;

	Tokcount = countToks(*buf, pattern);

	tok = strtok(*buf, pattern);
	if (tok == NULL)
		perror("no command passed: "), exit(EXIT_FAILURE);
	args = malloc(sizeof(char *) * (Tokcount + 1));
	if (args == NULL)
		perror("Error in Allocation"), exit(EXIT_FAILURE);
	args[0] = tok;

	while (tok != NULL)
	{
		tok = strtok(NULL, pattern);
		if (tok != NULL)
			args[i] = tok, i++;
	}
	args[i] = NULL;
	return (args);
}

unsigned int countToks(char *str, char *delim)
{
	int i = 0, j = 0;
	unsigned int count = 0;

	while (delim[i] != '\0')
	{
		while (str[j] != '\0')
		{
			if (delim[i] == str[j] && str[j + 1] != delim[i])
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}
