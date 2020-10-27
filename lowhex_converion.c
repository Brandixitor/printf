#include "holberton.h"
/**
 * lowerhex - hex conversion, lowercase ya salah
 * @buffer: buffer
 * @number: number
 * @pos: position
 * Return: Returns position
 */
int lowerhex(char *buffer, void *number, int pos)
{
	return (base_op(buffer, (size_t) number, 16, pos, 1));
}
