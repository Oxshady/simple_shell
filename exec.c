#include "main.h"

/**
 * _execve - custom implementation of the execve system call
 * @vect: an array of strings containing the command and arguments
 * @paths: an array of strings containing the directory paths
 *
 * Return: on failure, -1 is returned.
 */

int _execve(char **vect, char **paths)
{
	int contains_slash;

	if (!vect || !paths)
		return (-1);
	contains_slash = containsSlash(vect[0]);

	if (contains_slash == 0)
		return (executeFromPaths(vect, paths));
	else
		return (executeWithPath(vect));
}
