#include "main.h"
void tokenize(char *inp, int size, char ***vector)
{
	int token_counter = 0;
	char *token = NULL;
	char *delim = " \n\t";
	char *inp_copy = NULL;
	int i = 0;

	if (inp != NULL && size > 0)
	{
	inp_copy = (char *) malloc(sizeof(char) * size);
	if (inp_copy == NULL)
	{
		perror("error in memory allocation for input_copy");
	}

	strcpy(inp_copy,inp);

	token = strtok(inp, delim);
	
	while (token)
	{
		token = strtok(NULL, delim);
		token_counter++;
	}
	token = NULL;

	(*vector) = (char **) malloc(sizeof(char *) * (token_counter + 1));

	if ((*vector) == NULL)
	{
		perror("error for allocate memory to vector");
		free(inp_copy);
	}
	token = strtok(inp_copy,delim);
	while (token)
	{
		(*vector)[i] = (char *) malloc((strlen(token) + 1) * sizeof(char));
		if ((*vector)[i] == NULL)
		{
			perror("failed to allocate for individual st");
			for(size_t ii = 0; ii < i; ii++)
			{
				free((*vector)[ii]);
			}
			free(*vector);
			free(inp_copy);
		}
		strcpy((*vector)[i],token);
		i++;
		token = strtok(NULL,delim);
	}
	(*vector)[i] = NULL;
	free(inp_copy);
	}
}