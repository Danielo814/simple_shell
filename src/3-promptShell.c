#include "holberton.h"

unsigned int promptShell(void)
{
	char *buffer = NULL;
	size_t length = 0;
	char **args = NULL;
	char *pPath = NULL;
	ssize_t getCheck;
	unsigned int stat = _NORMAL;

	write(STDOUT_FILENO, "$ ", 2);
	getCheck = getline(&buffer, &length, stdin);

	if (getCheck == -1)
	{
		stat = _SHELL_END;
		exit(2);
	}
	if (getCheck == 1)
		stat = _SKIP;
	if (stat == _NORMAL)
		args = getToken(&buffer, " \n\t\r");


	if (stat == _NORMAL)
		stat = is_arg_ready(args[0]) ? _PATH_READY : _PATH_NREADY;
	if (stat == _PATH_NREADY)
	{
		pPath = getPathArgs(args[0], environ);
		stat = _PATH_READY;
	}
	if (stat == _PATH_READY)
	{
		execute(pPath ? pPath : args[0], args);
		wait(NULL);
	}

	if (args != NULL)
		free(args);
	if (pPath != NULL)
		free(pPath);
	if (buffer != NULL)
		free(buffer);
	return (stat);
}

unsigned int is_arg_ready(char *arg)
{
	if(access(arg, X_OK) == -1)
		return (0);
	else
		return (1);
}
