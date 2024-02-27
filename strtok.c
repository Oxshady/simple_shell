#include "main.h"
char **tokenize(char *inp) 
{	
	char **vector = NULL;
	int token_counter = 0; //////
	char *token = NULL;
	char *delim = " \n\t:";
	char *inp_copy = NULL;
	int i = 0; /////
	int size; ////////
	size = _strlen(inp);
	if(inp != NULL && size > 0)
	{
	inp_copy = (char *) malloc(sizeof(char) * (size + 1));
	if (inp_copy == NULL)
	{
		perror("error in memory allocation for input_copy");
		return NULL;
	}
	inp_copy[size] = '\0';
	_strcpy(inp_copy,inp);

	token = strtok(inp, delim);
	while (token)
	{
		token_counter++;
		token = strtok(NULL, delim);
	}
	token = NULL;
	if (token_counter != 0)
	{
		vector = (char **) malloc(sizeof(char *) * (token_counter + 1));
	}
	if (vector == NULL)
	{
		free(inp_copy);
		return (NULL);
	}
	token = strtok(inp_copy,delim);
	while (token)
	{
		vector[i] = (char *) malloc((_strlen(token + 1)) * sizeof(char));
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
		_strcpy(vector[i],token);
		i++;
		token = strtok(NULL,delim);
	}
	vector[i] = NULL;
	free(inp_copy);
	inp_copy = NULL;
	return vector;
	}
}