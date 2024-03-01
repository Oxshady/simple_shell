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
 * _atoi - converts a string to an integer
 *
 * @s: string input parameter
 *
 * Return: converted integer from string
*/

int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');
		else if (num > 0)
			break;
	} while (*s++);

	return (num * sign);
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
		char temp = buf[start];

		buf[start] = buf[end];
		buf[end] = temp;
		start++;
		end--;
	}
}
