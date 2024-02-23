#include "main.h"
void tokenize(char *inp, int size, char ***vector)
{
	int token_counter = 0;
	char *token = NULL;
	char *delim = " \n\t";
	char *inp_copy = NULL;
	int i = 0;

	inp_copy = (char *) malloc(sizeof(char) * size);
	if (inp_copy == NULL)
	{
		free(inp_copy);
		return 3;
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
		return(10);
	token = strtok(inp_copy,delim);
	while (token)
	{
		(*vector)[i] = (char *) malloc((strlen(token) + 1) * sizeof(char));
		if ((*vector)[i] == NULL)
			return 80;
		strcpy((*vector)[i],token);
		i++;
		token = strtok(NULL,delim);
	}
	(*vector)[i] = NULL;
}