#include "holberton.h"

/**
 * _strlen - prints the length of a string
 * Description: cycles through the array of s until its false
 * @s: input from file
 * Return: returns the length
 */
int _strlen(char *s)
{
	int counter = 0;
	/* initialize a counter for the length */

	while (s[counter] != 0) /*uses s to create an array for the input*/
		counter++; /*counts every element*/

	return (counter); /*return end counter8*/
}
