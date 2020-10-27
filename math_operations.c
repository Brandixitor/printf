#include "holberton.h"

/**
 * _abs - return absolute value of @num
 * @num: integer number
 *
 * Return: absolute value of @num
 */
int _abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

/**
 * itoa - convert integer @n to string @s
 * @n: integer number
 * @s: character array
 *
 * Return: returns int for position of format
 */
int itoa(int n, char s[])
{
	int i = 0;

	if (n / 10 != 0)
		i = itoa(n / 10, s);
	else if (n < 0)
		s[i++] = '-';

	s[i++] = _abs(n % 10) + '0';
	s[i] = '\0';

	return (i);
}

/**
 * uitoa - convert unsigned integer @n to string @s
 * @n: unsigned integer number
 * @s: character array
 *
 * Return: Returns int for position of format
 */
unsigned int uitoa(unsigned int n, char s[])
{
	unsigned int i = 0;

	if (n / 10 != 0)
		i = uitoa(n / 10, s);

	s[i++] = _abs(n % 10) + '0';
	s[i] = '\0';

	return (i);
}
