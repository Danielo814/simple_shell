#include "holberton.h"
/**
 * countToks - 
 * @str:
 * @delim:
 * Return:
 */
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
