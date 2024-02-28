#include "main.h"

/**
 * executeWithPath - excuted entered command directly
 * @vect: tokens of commands
 * Return: execution stat
*/
int executeWithPath(char **vect)
{
	if (execve(vect[0], vect, NULL) == -1)
		return (-1);
	return (0);
}
