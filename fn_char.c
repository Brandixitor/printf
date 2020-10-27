#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_c - prints a char and returns 1
 * @c: the list of arguments
 * Return: number of printed characters
 */
int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}
/**
 * print_s - prints a string and returns the length of string
 * @s: the list of arguments
 * Return: number of printed characters
 */
int print_s(va_list s)
{
	char *string;
	int i = 0;

	string = va_arg(s, char *);
	if (string == '\0')
	{
		string = "(null)";
	}
	for (i = 0; string[i]; i++)
	{
		_putchar(string[i]);
	}
	return (i);
}
/**
 * print_S - prints a string and returns the length of string
 * @S: the list of arguments
 * Return: number of printed characters
 */
int print_S(va_list S)
{
	char *string, hex[10];
	int i = 0, n = 0, j = 0;
	unsigned int count = 0;

	string = va_arg(S, char *);
	if (string == '\0')
		string = "(null)";
	for (i = 0; string[i]; i++)
	{
		j = 0;
		if ((string[i] > 0 && string[i] < 32) || (string[i] >= 127))
		{
			_putchar('\\');
			_putchar('x');
			n = string[i];
			if (n <= 15)
				_putchar('0');
			while (n > 0)
			{
				if (n % 16 >= 10 && n % 16 <= 15)
					hex[j] = 55 + (n % 16);
				else
					hex[j] = 48 + (n % 16);
				n = n / 16;
				j++;
			}
			for (--j; j >= 0; j--)
				_putchar(hex[j]);
			count += 4;
		}
		else
		{
			_putchar(string[i]);
			count++;
		}
	}
	return (count);
}
/**
* print_rot - prints the rot13'ed string
* @ro: the arguments list
* Return: number of printed characters
**/
int print_rot(va_list ro)
{
	char *s = va_arg(ro, char *);
	int i, j, count = 0;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		j = 0;
		while ((alpha[j] != '\0') && (s[i] != alpha[j]))
		{
			j++;
		}
		if (s[i] == alpha[j])
		{
			_putchar(rot[j]);
			count++;
		}
		else if (alpha[j] == '\0')
		{
			_putchar(s[i]);
			count++;
		}
	}
	return (count);
}
/**
* print_rs - prints the reversed string and returns the length of string
* @rs: the list of arguments
* Return: number of printed characters
**/
int print_rs(va_list rs)
{
	char *string;
	int i = 0, count = 0;

	string = va_arg(rs, char *);
	if (string == '\0')
	{
		string = ")llun(";
	}
	for (i = 0; string[i]; i++)
	{
		;
	}
	i--;

	for (; i >= 0; i--)
	{
		_putchar(string[i]);
		count++;
	}
	return (count);
}
