#include <unistd.h>
#include "holberton.h"
#include <stdio.h>
/**
 * _flush - fill the buffer with \0
 * @buffer: buffer;
 * The length of the buffer is defned in a macro
 * Return: pointer to buffer
 */
char *_flush(char *buffer)
{
	int i;

	for (i = 0; i < BUF_LENGTH; ++i)
		buffer[i] = '\0';
	return (buffer);
}

/**
 *fill_buffer - fills buffer
 * @buffer: buffer
 * @s: string to fill buffer 
 * @count_c: number of chars 
 * @s_length: length of string, 
 * Return: pointer to buffer
 */

char *fill_buffer(char *buffer, const char *s, int count_c, int s_length)
{
	int i, buffer_index;

	i = 0;
	buffer_index = (count_c > BUF_LENGTH) ? count_c % BUF_LENGTH : count_c;
	while (i < s_length)
	{
		if (buffer_index == BUF_LENGTH)
		{
			print_buffer(buffer, BUF_LENGTH);
			buffer = _flush(buffer);
			buffer_index = 0;
		}
		buffer[buffer_index] = s[i];
		++i;
		++buffer_index;
	}
	if (buffer_index == BUF_LENGTH)
	{
		print_buffer(buffer, BUF_LENGTH);
		buffer = _flush(buffer);
	}
	return (buffer);
}

/**
 * print_buffer - prints the buffer
 * @buffer: a buffer, char array
 * @length: number of characters I need to print
 *
 * Return: void
 */
void print_buffer(char *buffer, int length)
{

	if (length > BUF_LENGTH)
		length = length % BUF_LENGTH;
	write(1, buffer, length);
}
