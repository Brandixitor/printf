#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"
/**
*strange - prints letters after %.
*@format: pointer.
*@i: index.
*Return: count of putchar.
*/

int strange(const char *format, int i)
{
int j = 0;

	if (format[i] != '%')
	{
	_putchar(format[i - 1]);
	j += 1;
	}

_putchar(format[i]);
j += 1;
return (j);
}
