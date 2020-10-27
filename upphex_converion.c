#include "holberton.h"
/**
 * upperhex - hex conversion, uppercase ya salah
 * @buffer: buffer
 * @number: number
 * @pos: position
 * Return: Returns position
 */
int upperhex(char *buffer, void *number, int pos)
{
	return (base_op(buffer, (size_t) number, 16, pos, 0));
}

