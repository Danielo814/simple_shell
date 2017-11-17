#include "holberton.h"
#include <stdio.h>
/**
 * _strcpy - copys array from one pointer to another
 *
 * Description: loops through array and copies each element
 * @dest: pointer to destination file
 * @src: pointer to source file
 * Return: the array
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = src[i];
	return (dest);
}
