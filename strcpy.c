#include "main.h"
/**
 * _strncpy - function that copies a string
 * @dest:string to copy to
 * @src:string to copy from
 * @n: number of chars to copy
 * Return: address of first char in dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
