#include "main.h"
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
