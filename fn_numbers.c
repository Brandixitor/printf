#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 *_print_i - prints an integer
 *@vi: the list of arguments
 * Return: number of printed characters
 */
int _print_i(va_list vi)
{
	int i, num, div, o, n, count = 0;

	n = va_arg(vi, int);
	o = n % 10;
	n = n / 10;
	if (o < 0)
	{
		n = -n;
		o = -o;
		_putchar('-');
		count++;
	}
	num = n;
	div = 1;
	if (num > 0)
	{
		while ((num / 10) != 0)
		{
			num = num / 10;
			div = div * 10;
		}
		while (div >= 1)
		{
			i = n / div;
			_putchar(i + '0');
			count++;
			n = n % div;
			div = div / 10;
		}
	}
	_putchar(o + '0');
	count++;
	return (count);
}
/**
* _print_b - convert an integer to binary
* @b: the list of arguments
* Return: number of printed elment
**/
int _print_b(va_list b)
{
	unsigned int binary[32];
	int i = 0;
	unsigned int n = 0, count = 0;

	n = va_arg(b, unsigned int);
	if (n <= 1)
	{
		_putchar(n + '0');
		count++;
	}
	else
	{
	while (n > 0)
	{
		binary[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(binary[i] + '0');
		count++;
	}
	}
	return (count);
}
