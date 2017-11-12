#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void promptShell(void);
void getToken(char ***args, char **buf);
void shellInstance(void);
void execute(char **args);

#endif
