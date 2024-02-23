#include "main.h"

char *_path(char **env)
{
    size_t i, len_path;
    char *path = NULL;

    for (size_t i = 0; i < env[i] != NULL; i++)
    {
        if (strncmp(env[i], "PATH=", 5) == 0)
        {
            path = *env + 5;
            break;
        }
        if(env[i] == NULL)
        {
            return (NULL);
        }
        len_path = strlen(env[i]) - 5;
        path = (char *) malloc(sizeof(char) * (len_path + 1));
        if(path == NULL)
        {
            free(path);
            path = NULL;
            return (NULL);
        }

    }
    return (path);
}