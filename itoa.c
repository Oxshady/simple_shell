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

/**
 * revstr - Reverses a string
 * @buf: The string to reverse
 * @i: The length of the string
 */
void revstr(char *buf, int i)
{
	int start = 0;
	int end = i - 1;

	while (start < end)
	{
		/*Swap characters at start and end indices*/
		char temp = buf[start];

		buf[start] = buf[end];
		buf[end] = temp;

		/*Move indices towards the center*/
		start++;
		end--;
	}
}
