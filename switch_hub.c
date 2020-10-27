#include "holberton.h"
#include <stddef.h>

/**
 * switch_hub - determine which specifier to use
 * @format: pointer to format string from _printf
 * @buffer: pointer to buffer string from _printf
 * @i: position in @format
 * @j: position in @buffer
 * @args: list of arguments
 * @retval: current return value
 *
 * Return: new position in @format
 */
int switch_hub(const char *format, char *buffer, int i, int j,
	       va_list args, int *retval)
{
	int tempi;
	int (*func)(char *, void *, int, int *);
	void *tempptr;

	if (j >= 1022)
	{
		_print(buffer, retval);
		buffer[0] = '\0';
		j = 0;
	}
	tempptr = va_arg(args, void *);
	func = get_op_func(format[i]);
	if (func == NULL)
	{
		i = addthis(buffer, (char) format[i], i, retval);
		return (i);
	}
	tempi = func(buffer, tempptr, i, retval);
	i = tempi;
	return (i);
}

/**
 * get_op_func - gets operation function
 * @s: char to check function for
 *
 * Return: pointer to function
 */
int (*get_op_func(char s))(char *, void *, int, int *)
{
	op_t ops[] = {
		{'%', addpercent}, {'c', addchar}, {'s', addstring},
		{'i', addnum}, {'d', addnum}, {'u', addunum},
		{'b', binary}, {'X', upperhex}, {'x', lowerhex}, {'o', octal},
		{'r', rev}, {'R', rot13},
		{'-', addnum}, {'#', addnum}, {'+', addnum}, {'*', addnum},
		{'.', addnum}, {'p', address}, {'S', addnum}, {'h', addnum},
		{'l', addnum}, {'$', addnum},
	};
	int i;

	i = 0;
	while (i < 22)
	{
		if (ops[i].op == s)
			return (ops[i].f);
		i++;
	}
	return (NULL);

}
