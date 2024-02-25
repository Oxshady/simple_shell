#include "main.h"
int _execve(char **vect)
{
	if (vect)
	{
		if (execve(vect[0],vect,NULL) == -1)
			return -1;
		else
			return 0;
	}
}