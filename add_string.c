#include "holberton.h"
#include <stddef.h>
/**
* addstring - appends a string to another.
* @string: string.
* @add: string to be  added.
* @pos: position.
* @retval: ..
* Return: ..
*/
int addstring(char *string, void *add, int pos, int *retval)
{
int i;
char *tmp;

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
			tmp = _strdup(add);
			_print(string, retval);
			_print(tmp, retval);
			free(tmp);
			return (pos + 1);
			}
_strcat(string, (char *) add);
_print(string, retval);
return (pos + 1);
}
