#include "main.h"
/**
 * _get_env - function that get all enviroment variables
 * @env: pointers of strings (enviroment variables)
*/
void _get_env(char **en)
{
	int i = 0;
	while (en)
	{
		if (!en[i])
			break;
		write(1,en[i],_strlen(en[i]));
		write(1,"\n",1);
		i++;
	}
}