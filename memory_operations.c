#include "holberton.h"

/**
 * _strdup - return a pointer to a duplicate string of @str
 * @str: string to duplicate
 *
 * Return: pointer to duplicate string; NULL if insufficient memory
 */
char *_strdup(char *str)
{
	char *a;
	int i, size;


	if (str == NULL)
		return (NULL);
	size = _strlen(str);

	a = malloc((size + 1) * sizeof(char));

	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		a[i] = str[i];
	}
	a[i] = str[i];
	return (a);
}

/**
 * _calloc - mallocs assigned memory and sets to zero
 * @nmemb: number of memory spaces
 * @size: size of nmemb
 *
 * Return: returns pointer to allocated space, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *space;

	if (nmemb == 0 || size == 0)
		return (NULL);
	space = malloc(nmemb * size);
	if (space == NULL)
		return (NULL);
	for (i = 0; i != size; i++)
		*(space + (size * i)) = 0;
	return (space);
}
