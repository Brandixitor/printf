ucue#include "holberton.h"

/**
 * alpha - quick and dirty int to ascii
 * @r: int to convert
 *
 * Return: returns letter in proper ASCII format
 */
int alpha(int r)
{

	r >= 10 ? r += 55 : (r += '0');
	return (r);
}

/**
 * _tolower - convert a character string @string to lowercase letters
 * @string: string
 *
 * Return: pointer to @string
 */
char *_tolower(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
		{
			string[i] += 32;
			}
		i++;
	}
	return (string);
}
