#include "holberton.h"

/**
 * rot13 - encode string @s using rot13
 * @string: buffer
 * @add: string to encode and add
 * @pos: pos in format
 * @retval: 'global' return value of converted output strings
 *
 * Return: new pos in format
 */
int rot13(char *string, void *add, int pos, int *retval)
{
	int n, i;
	char *s;

	n = 0;
	s = _strdup(add);
	while (s[n])
	{
		if ((s[n] >= 'n' && s[n] <= 'z') ||
		    (s[n] >= 'N' && s[n] <= 'Z'))
		{
			s[n] -= 13;
		}
		else
		{
			while ((s[n] >= 'a' && s[n] <= 'm') ||
			       (s[n] >= 'A' && s[n] <= 'M'))
			{
				s[n] += 13;
			}
		}
		n++;
	}
	i = addstring(string, s, pos, retval);
	free(s);
	return (i);
}

/**
 * rev - reverses string in place, without printing it
 * @string: buffer
 * @add: string to encode and add
 * @pos: pos in format
 * @retval: 'global' return value of converted output strings
 *
 * Return: new pos in format
 */
int rev(char *string, void *add, int pos, int *retval)
{
	int i, len;
	char a, z;
	char *s;

	s = _strdup(add);
	len = _strlen(s) - 1;
	i = 0;
	while (i < len)
	{
		a = s[i];
		z = s[len];
		s[i++] = z;
		s[len--] = a;
	}

	i = addstring(string, s, pos, retval);
	free(s);
	return (i);
}

/**
 * address - adds formatted pointer addy to the buffer
 * @string: buffer
 * @add: string to encode and add
 * @pos: pos in format
 * @retval: 'global' return value of converted output strings
 *
 * Return: new pos in format
 */
int address(char *string, void *add, int pos, int *retval)
{
	int i;

	if (add == NULL)
	{
		i = addstring(string, "(nil)", pos, retval);
		return (i);
	}
	i = 0;
	while (string[i] != '\0')
		i++;
	string[i++] = '0';
	string[i++] = 'x';
	string[i] = '\0';

	return (base_op(string, (size_t) add, 16, pos, 1, retval));
}
