#include "main.h"
int _parent(char **pare) {
    char *pwd = getenv("PWD");
    char parent_directory[FILENAME_MAX];
    char *last_slash = NULL;
	size_t length;

    if (pwd == NULL) {
        perror("Unable to retrieve the current working directory.\n");
        return 1;
    }

    last_slash = strrchr(pwd, '/');

    if (last_slash == NULL) {
        perror("Parent directory does not exist.\n");
    } else if (last_slash == pwd) {
        *pare = strdup(pwd);
        if (*pare == NULL) {
            perror("Memory allocation failed.\n");
            return 1;
        }
        printf("/");
        return 0;
    } else {

        length = last_slash - pwd;
        strncpy(parent_directory, pwd, length);
        parent_directory[length] = '\0';

        printf("Parent directory: %s\n", parent_directory);
        *pare = strdup(parent_directory);
        if (*pare == NULL) {
            perror("Memory allocation failed.\n");
            return 1;
        }
    }
    return 0;
}
