<<<<<<< HEAD
#include "holberton.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
/**
* _printf - prints.
* @format: pointer.
* Return: ..
*/

int _printf(const char *format, ...)
{
	unsigned int count = 0, i = 0;
	int (*f)(va_list);
	va_list list;

	if (format == '\0')
		return (-1);
	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else if (format[i] == '\0')
			return (count);
		else if (format[i] == '%')
		{
			f = getspecifier(format, i + 1);
			i += 1;
			if (f == NULL)
			{
				count += strange(format, i);
			}
			else
			{
				count = count + f(list);
				if (format[i] == '+' || format[i] == ' ' || format[i] == '#')
					i++;
			}
		}
		i++;
	}
	va_end(list);
=======
#include <unistd.h>
#include <stdio.h>
#include "holberton.h"
/**
* _printf - prints and converts.
* @format: pointer.
* Return: ..
*/
int _printf(const char *format, ...)
{
	int f_i, count = 0;
	va_list args;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);
	va_start(args, format);
	if (args == NULL)
		return (-1);
	for (f_i = 0; format[f_i] != '\0'; f_i++)
	{
		if (format[f_i] == '%')
		{
			f_i++;
			if (format[f_i] == '\0')
			{
				return (-1);
			}
			while (format[f_i] == ' ')
				f_i++;
			func = get_spec_func(format[f_i]);
			if (func == NULL)
			{
				_putchar('%');
				_putchar(format[f_i]);
				count += 2;
			}
			else
				count += func(args);
		}
		else
		{
			_putchar(format[f_i]);
			count++;
		}
	}
	va_end(args);
>>>>>>> 8da219f8d72e7ef6c02836f8ed9a20cd5ff3331c
	return (count);
}
