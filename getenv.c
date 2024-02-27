#include "main.h"

/**
 * _get_env - Print the environment variables
 * @en: Pointer to the environment variables array
 */
void _get_env(char **en)
{
	int i = 0;

	while (en)
	{
		if (!en[i])
			break;
		write(1, en[i], _strlen(en[i]));
		write(1, "\n", 1);
		i++;
	}
}
