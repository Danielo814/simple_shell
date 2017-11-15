#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _ERROR 0
#define _NORMAL 1
#define _SKIP 2
#define _SHELL_END 3
#define _BUILT_IN 4
#define _PATH_NREADY 5
#define _PATH_READY 6

extern char **environ;

unsigned int promptShell(void);
char **getToken(char **buf, char *pattern);
void shellInstance();
void execute(char *arg, char **args);
unsigned int is_arg_ready(char *arg);
char *getKeyValue(char *key, char **env);
char *getPathArgs(char *prog, char **env);
char *get_x_args(char **env_paths, char *program);

#endif
