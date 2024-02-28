#include "main.h"
/**
 * _getline - function that get user input from STDIN stream
 * @inp: pointer to pointer to charachters
 * @size: size of input
 * Return: Number of bytes reads;
*/
size_t _getline(char **inp, size_t *size)
{
	ssize_t bytes;
	*size = 1024;

	*inp = (char *)calloc(*size, sizeof(char));
	if (*inp == NULL)
	{
		perror("Memory allocation failed");
		return (-1);
	}
	bytes = read(STDIN_FILENO, *inp, *size);
	if (bytes == -1)
	{
		perror("read"), free(*inp);
		return (-1);
	}
	if (bytes == 0)
	{
		free(*inp);
		return (0);
	}
	if (bytes == *size)
	{
		*size *= 2, *inp = (char *)realloc(*inp, *size * sizeof(char));
		if (*inp == NULL)
		{
			perror("Memory reallocation failed");
			return (-1);
		}
		bytes += read(STDIN_FILENO, *inp + bytes, *size - bytes);
	}
	*size = bytes, *inp = realloc(*inp, *size);

	if (*inp == NULL)
	{
		perror("Memory reallocation failed");
		return (-1);
	}
	(*inp)[bytes] = '\0';
	return (bytes);
}
