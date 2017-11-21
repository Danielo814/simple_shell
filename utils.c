#include "holberton.h"
/**
 * countToks - counts the number of tokens
 * @str: string we want to count
 * @delim: what delimiter we want to use
 * Return: the number of tokens
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
