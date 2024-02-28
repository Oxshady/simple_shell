#include "main.h"
/**
 * executeFromPaths - execute entered command that dosen't contain path of com
 * @vect: tokens of commands
 * @paths: tokens of pathes
 * Return: execution stat
*/
int executeFromPaths(char **vect, char **paths)
{
	int i;
	char *command_path = NULL;

	for (i = 0; paths[i] != NULL; i++)
	{
		if (paths[i][strlen(paths[i]) - 1] != '/')
		{
			command_path = createCommandPath(paths[i], vect[0]);

			if (!command_path)
				return (-1);
			if (execve(command_path, vect, NULL) != -1)
				return (0);
			free(command_path);
		}
	}
	return (3);
}
