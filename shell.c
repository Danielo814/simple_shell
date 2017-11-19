#include "holberton.h"

int main(void)
{
    int stat;

    do {
        stat = promptShell();
    } while (stat != _SHELL_END);

    return (EXIT_SUCCESS);
}

int promptShell(void)
{
    char *buffer = NULL;
    char *pPath = NULL;
    char **args = NULL;
    size_t length = 0;
    ssize_t getCheck;
    unsigned int stat = _NORMAL;

    stat = _NORMAL;
    write(STDOUT_FILENO, "$ ", 2);
    getCheck = getline(&buffer, &length, stdin);

    if (getCheck == -1)
        stat = _SHELL_END;
    else if (getCheck == 1)
        stat = _SKIP;
        
    if (stat == _NORMAL)
    {
        args = getToken(&buffer, " \n\t\r");
        if (access(args[0], X_OK) == -1)
            pPath = getPathArgs(args[0]);

        execute(pPath ? pPath : args[0], args);
    }

    if (stat == _SHELL_END)
        write(STDOUT_FILENO, "\n", 1);
    free(args);
    free(pPath);
    free(buffer);
    return (stat);
}

char **getToken(char **buf, char *pattern)
{
    int i = 1;
    char *tok;
    char **args;
    unsigned int tokCount;

    tokCount = countToks(*buf, pattern);

    tok = strtok(*buf, pattern);
    if (tok == NULL)
        perror("no command passed: "), exit(EXIT_FAILURE);
    args = malloc(sizeof(char *) * (tokCount + 1));
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

void execute(char *arg, char **args)
{
    pid_t pid;
    /*int status;*/

    pid = fork();
    if (pid == 0)
    {
        if (execve(arg, args, NULL) == -1)
            perror("Execute command failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == -1)
        perror("Fork error");
    else
    {
        wait(NULL);
        /*
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        */
    }
}
