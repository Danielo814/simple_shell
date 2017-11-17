#include "holberton.h"

char *getPathArgs(char *prog, char **env)
{
	char *tmp;
	char **tmp_args;

	tmp = getKeyValue("PATH", env);
	tmp_args = getToken(&tmp, ":");
	tmp = get_x_args(tmp_args, prog);

	return (tmp);
	free(tmp_args);
	free(tmp);
}
