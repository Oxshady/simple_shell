#include "main.h"
/**
 * _getline - function that get user input from STDIN stream
 * @inp: pointer to pointer to charachters
 * @size: size of input
 * Return: Number of bytes reads;
*/
size_t _getline(char **inp, size_t *size)
{
	return (getline(inp, size, stdin));
}
