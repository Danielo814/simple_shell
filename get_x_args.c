#include "holberton.h"

char *get_x_args(char **env_paths, char *program)
{
	int i = 1;
	char *tmp;

	tmp = _stralloc(3, env_paths[0], "/", program);
	while (access(tmp, X_OK) == -1 && env_paths[i] != NULL)
	{
		free(tmp);
		tmp = _stralloc(3, env_paths[i], "/", program);
		i++;
	}
	if (env_paths[i] == NULL)
		return (NULL);
	else
		return (tmp);
}

char *_stralloc(int count, ...)
{
	va_list list;
	char *tmp_arg;
	char *tmp_ptr;
	char *tmp_return;
	int sLen;
	int aLen;

	va_start(list, count);

	tmp_arg = va_arg(list, char *), count--;
	aLen = _strlen(tmp_arg);

	tmp_return = malloc(sizeof(char) * aLen + 1);
	if (tmp_return == NULL)
		exit (EXIT_FAILURE);

	_strcpy(tmp_return, tmp_arg);
	
	while (count != 0)
	{
		tmp_arg = va_arg(list, char *), count--;
		sLen = _strlen(tmp_return), aLen = _strlen(tmp_arg);

		tmp_ptr = malloc(sizeof(char) * (sLen + aLen) + 1);
		if (tmp_ptr == NULL)
			perror("check if second malloc failed");

		if (tmp_return != NULL)
			_strcpy(tmp_ptr, tmp_return), free(tmp_return);
		_strcat(tmp_ptr, tmp_arg), tmp_return = tmp_ptr;
	}

	va_end(list);
	return (tmp_return);
}
