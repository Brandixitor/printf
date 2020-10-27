#include "holberton.h"

/**
 * addchar - adds a single char to the buffer
 * @string: string being extended
 * @add: string to add to @string
 * @pos: format position, incremented in function for switch_hub brevity
 * @retval: 'global' return value of converted output strings
 *
 * Return: pointer to @string
 */
int addchar(char *string, void *add, int pos, int *retval)
{
	int i;
	char temp[2];

	i = 0;

	while (string[i] != '\0')
		i++;
	if (i + 1 >= 1022)
	{
		_print(string, retval);
		string[0] = '\0';
	}
	temp[0] = ((size_t) add);
	temp[1] = '\0';

	if (temp[0] == '\0')
	{
		_print(string, retval);
		_putchar(0, retval);
		*retval += 1;
		string[0] = '\0';
		return (pos + 1);
	}
	else
		_strcat(string, temp);
	return (pos + 1);
}

/**
 * addpercent - adds a percent to the buffer
 * @string: string being extended
 * @add: string to add to @string
 * @pos: format position, incremented in function for switch_hub brevity
 * @retval: 'global' return value of converted output strings
 *
 * Return: pointer to @string
 */
int addpercent(char *string, void *add, int pos, int *retval)
{
	int i;
	char temp[2];

	(void) add;
	i = 0;

	while (string[i] != '\0')
		i++;
	if (i + 1 >= 1022)
	{
		_print(string, retval);
		string[0] = '\0';
	}
	temp[0] = '%';
	temp[1] = '\0';

	_strcat(string, temp);
	return (pos + 1);
}

/**
 * addthis - adds % and current format char
 * @string: string being extended
 * @add: string to add to @string
 * @pos: format position, incremented in function for switch_hub brevity
 * @retval: 'global' return value of converted output strings
 *
 * Return: pointer to @string
 */
int addthis(char *string, char add, int pos, int *retval)
{
	int i;
	char temp[3];

	i = 0;
	while (string[i] != '\0')
		i++;
	if (i + 1 >= 1022)
	{
		_print(string, retval);
		string[0] = '\0';
	}
	temp[0] = '%';
	temp[1] = add;
	temp[2] = '\0';
	_strcat(string, temp);

	return (pos + 1);
}



/**
 * addunum - convert unsigned @num to string and append it to string @string
 * @string: string being appended
 * @num: number to convert to characters and append
 * @pos: position of format, incremented upon conversion for switch_hub brevity
 * @retval: 'global' return value of converted output strings
 *
 * Return: @pos + 1
 */
int addunum(char *string, void *num, int pos, int *retval)
{
	char temp[1000];
	unsigned int number;

	number = (size_t) num;
	uitoa(number, temp);
	addstring(string, temp, 0, retval);

	return (pos + 1);
}

/**
 * addnum - convert signed @num to string and append it to string @string
 * @string: string being appended
 * @num: number to convert to characters and append
 * @pos: position of format, incremented upon conversion for switch_hub brevity
 * @retval: 'global' return value of converted output strings
 *
 * Return: @pos + 1
 */
int addnum(char *string, void *num, int pos, int *retval)
{
	char temp[100];

	itoa((size_t) num, temp);
	addstring(string, temp, 0, retval);

	return (pos + 1);
}
