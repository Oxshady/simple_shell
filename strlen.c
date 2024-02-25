#include "main.h"
/**
 * _strlen - count the number of character of the string
 * @s: the string i will count it's characters
 * Return: the number of characters
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != 0)
	{
		i++;
	}
	return (i);
}
