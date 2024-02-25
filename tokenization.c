#include "main.h"
char **tokenize(char *inp, int size) 
{	
	char **vector = NULL;
	int token_counter = 0;
	char *token = NULL;
	char *delim = " \n\t";
	char *inp_copy = NULL;
	int i = 0;
	if (inp != NULL && size > 0)
	{
	inp_copy = (char *) malloc(sizeof(char) * (size + 1));
	if (inp_copy == NULL)
	{
		perror("error in memory allocation for input_copy");
		return NULL;
	}
	inp_copy[size] = '\0';
	strcpy(inp_copy,inp);

	token = strtok(inp, delim);
	if (token != NULL)
		token_counter = 1;
	while (token)
	{
		token = strtok(NULL, delim);
		token_counter++;
	}
	token = NULL;

	vector = (char **) malloc(sizeof(char *) * (token_counter));

	if (vector == NULL)
	{
		perror("error for allocate memory to vector");
		free(inp_copy);
		return (NULL);
	}
	token = strtok(inp_copy,delim);
	while (token)
	{
		vector[i] = (char *) malloc((strlen(token) + 1) * sizeof(char));
		if (vector[i] == NULL)
		{
			perror("failed to allocate for individual st");
			for(size_t ii = 0; ii < i; ii++)
			{
				free(vector[ii]);
			}
			free(vector);
			(vector) = NULL;
			free(inp_copy);
			inp_copy = NULL;
			return NULL;
		}
		strcpy(vector[i],token);
		i++;
		token = strtok(NULL,delim);
	}
	vector[i] = NULL;
	free(inp_copy);
	inp_copy = NULL;
	return vector;
	}
}