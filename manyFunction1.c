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
/**
 * _strcpy - copy the string from source to distination
 * Description: function that copies the string pointed to by src
 * including the terminating null byte (\0), to the buffer pointed to by dest
 * @dest: array of characters to copy to
 * @src: string to copy from
 * Return: address of the first location of the dest
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}
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

