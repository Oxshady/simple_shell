#include "main.h"
/**
 * createCommandPath - create path with / then conc with command
 * @path: paths of bins
 * @command: command to cat with path
 * Return: concatenated slashed path with command
*/
char *createCommandPath(char *path, char *command)
{
	char *single_path = NULL;
	char *command_path = NULL;

	if (!path || !command)
		return (NULL);

	single_path = calloc(strlen(path) + 2, sizeof(char));
	if (!single_path)
		return (NULL);

	strcpy(single_path, path);
	strcat(single_path, "/");
	command_path = calloc(strlen(single_path)
	 + strlen(command) + 1, sizeof(char));
	if (!command_path)
	{
		free(single_path);
		return (NULL);
	}
	strcpy(command_path, single_path);
	strcat(command_path, command);

	free(single_path);
	return (command_path);
}
