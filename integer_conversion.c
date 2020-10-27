#include "holberton.h"
/**
 * base_op - converts an integer into desired base, adds to buffer ha saliih
 * @buffer: string
 * @number: int
 * @base: base
 * @pos: format position
 * @lower: flag
 * Return: pointer to string
 */
int base_op(char *buffer, unsigned int number, int base, int pos, int lower)
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
	addstring(buffer, converted_number, 0);
	free(converted_number);

	return (pos + 1);
}
