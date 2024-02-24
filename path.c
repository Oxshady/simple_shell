#include "main.h"
extern char **__environ;
char *_path(void)
{
    size_t i = 0, len_path = 0;
    char *path = NULL;

    for (i = 0; __environ[i] != NULL; i++)    
    {
        if (strncmp(__environ[i], "PATH=", 5) == 0)
        {
            len_path = (strlen(__environ[i]) - 5);
            path = (char *) malloc(sizeof(char) * (len_path + 1));
            if (path == NULL)
                return NULL;
            strcpy(path,((__environ[i]) + 5));
            break;
        }
        if(__environ[i]== NULL)
            return (NULL);
    }
    return (path);
}
