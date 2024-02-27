#include "main.h"

/**
 * setenv_unset - Set or unset an environment variable
 * @vect: Array of strings containing the command and arguments
 * @val: 1 to unset the variable, 0 to set the variable
 *
 * Return: 0 on success, -1 on failure
 */
int setenv_unset(char **vect, int val)
{
	char *line = NULL;
	char *varName = NULL;
	char *value = NULL;

	if (vect == NULL || vect[1] == NULL)
	{
		perror("invalid");
		return (-1);
	}
	line = strdup(vect[1]);
	varName = strtok(line, "=");

	if (varName == NULL)
	{
		return (-1);
	}
	if (val == 1)
	{
		if (unsetenv(varName) == 0)
		{
			printf("unseted");
			free(line);
		}
		return (1);
	}
	value = strtok(NULL, "\0");
	if (value[0] == '"' && value[strlen(value) - 1] == '"')
	{
		value[strlen(value) - 1] = '\0';
		value++;
	}
	if (setenv(varName, value, 1) == 0)
	{
		printf("export suxxe");
		return (0);
	}
	else
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}
