#include "main.h"

/**
 * _chdir - function that changes directory
 * @vect: tokens --> pointer to strings
 * Return: return status of function
 */
int _chdir(char **vect)
{
    char *home = getenv("HOME"), *previous = getenv("OLDPWD");
    char *path = NULL;
    int result = -1;

    if (vect == NULL || vect[1] == NULL)
        return -1;

    path = strdup(vect[1]);
    if (path == NULL)
        return -1;

    if (strcmp(path, ".") == 0 || strcmp(path, "~") == 0)
    {
        free(path);
        return chdir(".") == 0 ? 0 : -1;
    }
    else if (strcmp(path, "-") == 0) {
        if (!previous) {
            free(path);
            return -1;
        }
        free(path);
        return chdir(previous) == 0 ? 0 : -1;
    }

    else if (strcmp(path, "..") == 0)
    {
        free(path);
        return chdir("..") == 0 ? 0 : -1;
    }

    result = chdir(path);

    free(path);

    return result == 0 ? 0 : -1;
}