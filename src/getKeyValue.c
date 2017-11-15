#include "holberton.h"

char *getKeyValue(char *key, char **env)
{
	int i = 0;
	char *tmp = NULL;

	while (env[i] && tmp == NULL)
	{
		tmp = strstr(env[i], key);
		i++;
	}

	tmp = strstr(tmp, "="), tmp++;
	return (tmp);
}
