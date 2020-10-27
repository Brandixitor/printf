#include "holberton.h"
/**
 * rev - reverses string in place, without printing it
 *
 * @string: string to reverse
 * Return: pointer to string
 */
char *rev(char *string)
{
	int i, len;
	char a, z;
	char *s;

	s = _strdup(string);
	len = _strlen(s) - 1;
	i = 0;
	while (i < len)
	{
		a = s[i];
		z = s[len];
		s[i++] = z;
		s[len--] = a;
	}

	return (s);
}
