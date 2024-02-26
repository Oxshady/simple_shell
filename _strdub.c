#include "main.h"

/**
 * _strdub - duplicates a string
 * @str: string of duplicates
 * Return: pointer of duplicates
 */

char *_strdub(const char *str)
{
    int len = 0;
    char *x;

    if(str == NULL)
    {
        return (NULL);
    }
    while (*str++)
        len++;
    x = malloc(sizeof(char) * (len + 1));
    if (!x)
    {
        return (NULL);
    }
    for(len++; len--;)
        x[len] = *--str;
    return (x);
}