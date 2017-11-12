#include "holberton.h"

void getToken(char ***args, char **buf)
{
	int i = 1;
	char *tok;

	tok = strtok(*buf, " \n\t");
	if (tok == NULL)
		perror("no command passed: "), exit(1);
	*args = malloc(sizeof(char *) * 2);
	if (args == NULL)
		perror("Error in Allocation"), exit(1);
	*args[0] = tok;

	while (tok != NULL)
	{
		tok = strtok(NULL, " \n\t");
		if (tok != NULL)
		{
			*args = realloc(*args, sizeof(char *) * (i + 2));
			if (args == NULL)
			{
				free(buf);
				perror("Error in realloc");
				exit(0);
			}
			*args[i] = tok, i++;
		}
	}
	args[i] = NULL;
}
