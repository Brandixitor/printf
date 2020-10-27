#include "holberton.h"
/**
 * octal - octal conversion ya salah
 * @buffer: buffer
 * @number: number
 * @pos: position
 * Return: Returns position
 */
int octal(char *buffer, void *number, int pos)
{
	return (base_op(buffer, (size_t) number, 8, pos, 1));
}
