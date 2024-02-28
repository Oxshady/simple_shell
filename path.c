#include "main.h"

/**
 * _path - Extracts the PATH environment variable
 * @str: Pointer to store the PATH environment variable
 *
 * Return: Pointer to the PATH environment variable
 */

char *_path(char **str)
{
size_t i = 0, len_path = 0;

for (i = 0; __environ[i] != NULL; i++)
{
if (strncmp(__environ[i], "PATH=", 5) == 0)
{
len_path = (strlen(__environ[i]) - 5);
*(str) = (char *) malloc(sizeof(char) * (len_path + 1));
if ((*str) == NULL)
return (NULL);
strcpy(*(str), ((__environ[i]) + 5));
break;
}
if (__environ[i] == NULL)
return (NULL);
}
return (NULL);
}
