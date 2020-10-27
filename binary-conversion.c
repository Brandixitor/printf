#include "holberton.h"

/**
 * binary - converts to binary ya salah
 * @buffer: buffer
 * @number: number
 * @pos: position
 * Return: Returns position
 */
int binary(char *buffer, void *number, int pos)
{
	return (base_op(buffer, (size_t) number, 2, pos, 1));
}
