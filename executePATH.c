#include "main.h"

/**
 * executeWithPath - execute with pathes
 * @vect: tokens
 * Return: int rep stat
*/
int executeWithPath(char **vect)
{
	if (execve(vect[0], vect, NULL) == -1)
		return (-1);
	return (0);
}
