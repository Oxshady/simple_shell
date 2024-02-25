#include "main.h"
int _execve(char **vect,char **paths)
{
	int i = 0;
	char *dest;
	char *copu = NULL;
	if (vect)
	{
		while (paths[i])
		{
			dest =strcat(paths[i],vect[0]);
			if (dest == NULL)
				return 2;
			printf("%s\n",dest);
			i++;
		}
	}
}