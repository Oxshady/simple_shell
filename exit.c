#include "main.h"
/**
 * _exitt - function that exit code with stat
 * @vect: pointer to pointer to characters --> tokens
 * Return: status
*/
int _exitt(char **vect)
{
	char *x = "exit";

	if (vect == NULL || vect[0] == NULL)
		return (-1);
	int exit_code = 0;

	if (strncmp(vect[0], x, strlen(x)) == 0)
	{
		if (vect[1] != NULL)
		{
			exit_code = atoi(vect[1]);
			return (exit_code);
		}
		else
			return (0);
	}
	return (-1);
}
