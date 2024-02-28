#include "main.h"
/**
 * _strcat - function that concatenates two strings
 * @dest: first string
 * @src: sencond string
 * Return: the address of the
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, ii = 0;

	while (*(dest + i) != '\0')
		i++;
	while (*(src + ii) != '\0')
	{
		*(dest + i) = *(src + ii);
		i++;
		ii++;
	}
	*(dest + i) = '\0';
	return (dest);
}
