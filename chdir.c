#include "main.h"
/**
 * _chdir - function that change directory
 * @vect: tokens --> pointer to strings
 * Return: return stat of function
*/
int _chdir(char **vect)
{
char *home = getenv("HOME"), *parent = NULL, *path;
char *previous = getenv("OLDPWD"), *arr[] = {".", "-", "..", "~", " "};

_parent(&parent), path  = NULL;
	if (vect[0] != NULL && vect[1] == NULL)
	{
		chdir(home);
		return (0);
	}
if (vect == NULL || vect[1] == NULL)
	return (-1);
path = strdup(vect[1]);
if (path == NULL)
	return (-1);
if (strcmp(path, arr[0]) == 0)
{
	free(path);
	return (0);
}
	else if (strcmp(path, arr[1]) == 0)
	{
		free(path);
		return (chdir(previous));
	}
	else if (strcmp(path, arr[2]) == 0)
{
		free(path);
		return (chdir(parent));
}
else if (strcmp(path, arr[3]) == 0 || strcmp(path, arr[4]) == 0)
{
return (chdir(home));
}
else
{
int result = chdir(path);
free(path);
return (result);
}
}
