#include "holberton.h"
#include <stddef.h>
/**
* _print - prints a string to stdout.
* @string: string to print.
* @retval: ..
* Return: 1 on success.
*/
int _print(char *string, int *retval)
{
int i;

	if (string != NULL)
	{
	*retval += _strlen(string);
	write(1, string, (_strlen(string)));
		for (i = 0; i < 1024; i++)
		{
		string[i] = '\0';
		}
	}
return (1);
}
