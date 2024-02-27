#include "main.h"

/**
 * _itoa - Converts an integer to a string
 * @num: The integer to convert
 *
 * Return: The converted string
 */
char *_itoa(int num)
{
char buf[25];
int i = 0;

if (num == 0)
	buf[i++] = '0';
else
{
	while (num > 0)
	{
		buf[i++] = (num % 10) + '0';
		num /= 10;
	}
}
	buf[i] = '\0';
	revstr(buf, i);

	return (strdup(buf));
}
