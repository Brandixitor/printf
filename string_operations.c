#include "holberton.h"

/**
 * _strlen - returns length of string @s
 * @s: pointer to string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strncpy - copy @n bytes of string @src to string @dest
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: bytes of @src to copy
 *
 * Return: pointer to @dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i != n)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
		{
			while (i != n)
				dest[i++] = '\0';
			break;
		}
		i++;
	}
	return (dest);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @retval: 'global' return value of converted output strings
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, int *retval)
{
	*retval += 1;
	return (write(1, &c, 1));
}


/**
 * _strcat - concat strings, src appended to dest
 * @dest: destination string
 * @src: source string
 *
 * Return: returns finished string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
