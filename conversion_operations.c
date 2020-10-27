#include "holberton.h"

/**
 * binary - converts to binary
 *
 * @buffer: buffer
 * @number: number to convert
 * @pos: position in format
 * @retval: 'global' return value of converted output strings
 *
 * Return: Returns next position in format
 */
int binary(char *buffer, void *number, int pos, int *retval)
{
	unsigned int num;

	num = (size_t) number;
	return (base_op(buffer, num, 2, pos, 1, retval));
}

/**
 * octal - octal conversion
 *
 * @buffer: buffer
 * @number: number to convert
 * @pos: position in format
 * @retval: 'global' return value of converted output strings
 *
 * Return: Returns next position in format
 */
int octal(char *buffer, void *number, int pos, int *retval)
{
	unsigned int num;

	num = (size_t) number;
	return (base_op(buffer, num, 8, pos, 1, retval));
}

/**
 * upperhex - hex conversion, uppercase
 *
 * @buffer: buffer
 * @number: number to convert
 * @pos: position in format
 * @retval: 'global' return value of converted output strings
 *
 * Return: Returns next position in format
 */
int upperhex(char *buffer, void *number, int pos, int *retval)
{
	unsigned int num;

	num = (size_t) number;
	return (base_op(buffer, num, 16, pos, 0, retval));
}

/**
 * lowerhex - hex conversion, lowercase
 *
 * @buffer: buffer
 * @number: number to convert
 * @pos: position in format
 * @retval: 'global' return value of converted output strings
 *
 * Return: Returns next position in format
 */
int lowerhex(char *buffer, void *number, int pos, int *retval)
{
	unsigned int num;

	num = (size_t) number;
	return (base_op(buffer, num, 16, pos, 1, retval));
}

/**
 * base_op - converts an integer into desired base, adds to buffer
 * @buffer: string to append
 * @number: int to convert
 * @base: base to convert to
 * @pos: format position, used here for switch_hub brevity
 * @lower: flag denoting lowercase for hex if == 1
 * @retval: 'global' return value of converted output strings
 *
 * Return: returns pointer to converted string
 */
int base_op(char *buffer, unsigned long number,
	    int base, int pos, int lower, int *retval)
{
	char pre_convert[32];
	char *converted_number;
	unsigned int remain;
	int i, j;

	converted_number = malloc(32);
	for (i = 0; number >= (unsigned int) base; i++)
	{
		remain = (number % base);
		number /= base;
		pre_convert[i] = alpha(remain);
	}

	pre_convert[i] = alpha(number);

	for (j = 0; i >= 0; j++, i--)
	{
		converted_number[j] = pre_convert[i];
	}

	converted_number[j] = '\0';

	if (lower == 1)
		converted_number = _tolower(converted_number);
	addstring(buffer, converted_number, 0, retval);
	free(converted_number);

	return (pos + 1);
}
