#include "holberton.h"
#include <stddef.h>

/**
 * _printf - print @format and convert specifiers with corresponding arguments
 * @format: pointer to input string
 *
 * Return: length of output string
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, tmpi, retval;
	char buffer[1024];

	if (format == NULL)
		return (0);
	buffer[0] = '\0';
	i = j = tmpi = retval = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		while (format[i] != '\0' && format[i] != '%')
		{
			if (j > 1022)
			{
				buffer[j] = '\0';
				_print(buffer, &retval);
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
			tmpi = switch_hub(format, buffer, i, _strlen(buffer),
					  args, &retval);
			i = tmpi;
		}
		j = _strlen(buffer);
	}
	va_end(args);
	_print(buffer, &retval);
	return (retval);
}

/**
 * addstring - append string @add to string @string
 * @string: string being extended
 * @add: string to add to @string
 * @pos: format position, incremented in function for switch_hub brevity
 * @retval: 'global' return value of converted output strings
 *
 * Return: pointer to @string
 */
int addstring(char *string, void *add, int pos, int *retval)
{
	int i;
	char *tempstring;

	i = 0;
	if ((char *) add == NULL)
	{
		_strcat(string, "(null)");
		return (pos + 1);
	}
	while (string[i] != '\0')
		i++;
	if (i + _strlen((char *) add) >= 1022)
	{
		tempstring = _strdup(add);
		_print(string, retval);
		_print(tempstring, retval);
		free(tempstring);
		return (pos + 1);
	}
	_strcat(string, (char *) add);
	_print(string, retval);
	return (pos + 1);
}

/**
 * _print - prints a string to stdout
 * @string: string to print
 * @retval: 'global' return value of converted output strings
 *
 * Return: returns 1 on success
 */
int _print(char *string, int *retval)
{
	int k;

	if (string != NULL)
	{
		*retval += _strlen(string);
		write(1, string, (_strlen(string)));
		for (k = 0; k < 1024; k++)
		{
			string[k] = '\0';
		}
	}
	return (1);
}
