#include "main.h"

/**
 * _execve - Custom implementation of the execve system call
 * @vect: An array of strings containing the command and arguments
 * @paths: An array of strings containing the directory paths
 *
 * Return: On success.
 * this function does not return. On failure, -1 is returned.
 */

int _execve(char **vect, char **paths)
{
	char *single_path = NULL, *command_path = NULL;
	int i = 0, ii = 0, sta = 0, strle = 0, stat = 0;

	if (!vect || !paths)
		return (-1);
	if (vect[0])
	{
		while (vect[0][ii])
		{
			if (vect[0][ii] == '/')
			{
				sta = 1;
				break;
			}
			else
				sta = 0;
			ii++;
		}}
	if (sta == 0)
	{
	for (i = 0; paths[i] != NULL; i++)
	{
		strle = strlen(paths[i]) - 1;
		if (paths[i][strle] == '/')
			continue;
		else
		{
			single_path = (char *)calloc(sizeof(char), strlen(paths[i]) + 2);
			if (single_path == NULL)
				return (0);
			strcpy(single_path, paths[i]), strcat(single_path, "/");
			command_path = (char *) calloc(sizeof(char),
			(strlen(single_path) + strlen(vect[0]) + 1));
			strcpy(command_path, single_path), strcat(command_path, vect[0]);
			if (execve(command_path, vect, NULL) == -1)
			{
				stat = 3;
				continue;
			}
			else
				break;
			}
		free(single_path), single_path = NULL;
	}}
	else
		if (execve(vect[0], vect, NULL) == -1)
		return (-1);
}
