#include "main.h"
/**
 * tokenize - Splits a string into tokens based on delimiters
 * @inp: The input string to be tokenized
 *
 * Return: A pointer to an array of tokens
 */
char **tokenize(char *inp)
{
char **vector = NULL;
char *token = NULL, *delim = " \n\t:", *inp_copy = NULL;
int i = 0, size, token_counter = 0, ii = 0;

size = _strlen(inp);
if (inp != NULL && size > 0)
{inp_copy = (char *)malloc(sizeof(char) * (size + 1));
if (inp_copy == NULL)
return (NULL);
_strcpy(inp_copy, inp);
inp_copy[size] = '\0';
token = strtok(inp, delim);
while (token)
token_counter++, token = strtok(NULL, delim);
token = NULL;
if (token_counter != 0)
vector = (char **)calloc(sizeof(char *), (token_counter + 1));
if (vector == NULL)
{free(inp_copy);
return (NULL);
}
token = strtok(inp_copy, delim);
while (token)
{vector[i] = (char *)calloc((_strlen(token) + 1), sizeof(char));
if (strcmp(token, "#") == 0)
break;
if (vector[i] == NULL)
{
for (ii = 0; ii < i; ii++)
free(vector[ii]);
free(vector);
free(inp_copy);
return (NULL);
}
_strcpy(vector[i], token), i++, token = strtok(NULL, delim);
}
vector[i] = NULL;
free(inp_copy);
}
return (vector);
}
