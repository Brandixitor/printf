#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
/**
*_plus_i - prints an integer with flag plus
*@vi: the list of arguments
* Return: number of printed characters
*/
int _plus_i(va_list vi)
{
int i, num, div, o, n, count = 0;
n = va_arg(vi, int);
o = n % 10;
n = n / 10;
if (o >= 0)
{
_putchar('+');
count++;
}
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
*_space_i - prints an integer with flag space
*@vi: the list of arguments
* Return: number of printed characters
*/
int _space_i(va_list vi)
{
int i, num, div, o, n, count = 0;

n = va_arg(vi, int);
o = n % 10;
n = n / 10;
if (o >= 0)
{
_putchar(' ');
count++;
}
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
* _diez_o - prints an octal with prefix 0
* @o: the list of arguments
* Return: number of printed characters
*/
int _diez_o(va_list o)
{
unsigned int octal[10];
	unsigned int count = 0, n = 0;
	int i = 0;

	n = va_arg(o, unsigned int);

		_putchar('0');
		count++;
	while (n > 0)
	{
		octal[i] = n % 8;
		n = n / 8;
		i++;
	}
	for (--i; i >= 0; i--)
	{
		_putchar(octal[i] + '0');
		count++;
	}
	return (count);
}
/**
* _diez_x - prints input integer to an hexadecimal in lowercase with prefix 0x
* @x: the list of arguments
* Return: number of printed characters
*/
int _diez_x(va_list x)
{
char hex[20];
	unsigned int count = 0, n = 0;
	int i = 0;

	n = va_arg(x, unsigned int);
		_putchar(0 + '0');
		count++;
	if (n != 0)
	{
	_putchar('x');
	count++;
	}
	while (n > 0)
	{
		if (n % 16 >= 10 && n % 16 <= 15)
			hex[i] = 87 + (n % 16);
		else
			hex[i] = 48 + (n % 16);
		n = n / 16;
		i++;
	}
	for (--i; i >= 0; i--)
	{
		_putchar(hex[i]);
		count++;
	}
	return (count);
}
/**
* _diez_X - prints input integer to an hexadecimal in uppercase with pre 0X
* @X: the list of arguments
* Return: number of printed characters
*/
int _diez_X(va_list X)
{
	char hex[20];
	unsigned int count = 0, n = 0;
	int i = 0;

	n = va_arg(X, unsigned int);
		_putchar(0 + '0');
		count++;
	if (n != 0)
	{
	_putchar('X');
	count++;
	}
	while (n > 0)
	{
		if (n % 16 >= 10 && n % 16 <= 15)
			hex[i] = 55 + (n % 16);
		else
			hex[i] = 48 + (n % 16);
		n = n / 16;
		i++;
	}
	for (--i; i >= 0; i--)
	{
		_putchar(hex[i]);
		count++;
	}
	return (count);
}
