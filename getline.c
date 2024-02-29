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

	*inp = (char *)malloc(*size * sizeof(char));
	if (*inp == NULL)
	{
		perror("Memory allocation failed");
		return (-1); // -> inp NULL
	}
	bytes = read(STDIN_FILENO, *inp, *size);
	if (bytes == -1)
	{
		perror("read");
		free(*inp);
		return (-1); // error read
	}
	if (bytes == 0)
	{
		free(*inp);
		return (0);
	}
	*size = bytes, *inp = realloc(*inp, *size);
	
	if (*inp == NULL)
	{
		perror("Memory reallocation failed");
		return (-1);
	}
	if (bytes > 0)
	{
		(*inp)[bytes - 1] = '\0';
	}
	return (bytes);
}
// free on error -1
// free on EOF 0
