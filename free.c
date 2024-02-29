#include "main.h"

void free_mem(char ***vector)
{
	int i;

	i = 0;
	while ((*vector)[i] != NULL)
	{
		free((*vector)[i]);
		i++;
	}
	free((*vector));
	vector = NULL;
}