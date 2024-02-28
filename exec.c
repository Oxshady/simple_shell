#include "main.h"

/**
 * _execve - Custom implementation of the execve system call
 * @vect: An array of strings containing the command and arguments
 * @paths: An array of strings containing the directory paths
 *
 * Return: On success, this function does not return.
 *         On failure, -1 is returned.
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
