#include "main.h"
int _execvp(char **vect)
{
	if (vect)
	{
		if (execvp(vect[0],vect) == -1)
			return -1;
		else
			return 0;
	}
}