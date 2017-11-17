#include "holberton.h"

/**
 * _strcat - concatenates two strings
 *
 * Description: finds the end of a strings and copies the string from there
 * @dest: destination array
 * @src: sourse array
 * Return: returns the destination file
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	for (j = 0 ; src[j] != '\0' ; j++, i++)
	{
		dest[i] = src[j];
	}

	dest[i] =  '\0';
	return (dest);
}
