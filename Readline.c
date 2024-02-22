
#include "main.h"
/**
 * Read_line - function that read data from the user (standard input)
 * @input: double pointer to the string to be read
 * @size: the size of input string
 * Return: 0 if EOF EXIT-FAIULE if error number of chars if end successfully
*/
ssize_t Read_line(char **input, size_t *size)
{
	ssize_t Read = getline(input, size, stdin);
	if (Read == -1)
	{
		if (feof(stdin))
		{
			*input = NULL;
			exit(0);
		}
		else
		{
			*input = NULL;
			return(-1);
		}
	}
	return (Read);
}
