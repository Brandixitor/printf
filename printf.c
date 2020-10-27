#include "holberton.h"
#include <stddef.h>
/**
* _printf - prints and converts.
* @format: pointer.
* Return: ..
*/
int _printf(const char *format, ...)
{
va_list args;
int i, j, k, tmp;
char buffer[1024];

	if (format == NULL)
	return (0);
		buffer[0] = '\0';
		i = j = tmp = k = 0;
		va_start(args, format);
	while (format[i] != '\0')
	{
		while (format[i] != '\0' && format[i] != '%')
		{
			if (j > 1022)
			{
			buffer[j] = '\0';
			_print(buffer, &k);
			j = 0;
			}
				buffer[j] = format[i];
				i++;
				j++;
		}
	buffer[j] = '\0';
			if (format[i] == '%')
			{
			i++;
			tmp = switch_hub(format, buffer, i, _strlen(buffer),
			  args, &k);
			i = tmp;
		}
		j = _strlen(buffer);
	}
	va_end(args);
	_print(buffer, &k);
	return (k);
}
