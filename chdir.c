#include "main.h"
int _chdir(char **vect) {
    char *home = getenv("HOME");
    char *dot = getenv("PWD");
    char *previous = getenv("OLDPWD");
    char *arr[] = {".", "..", "-", "~", " "};
    char *parent = NULL;
    char *path = NULL;

    _parent(&parent); 

    if (vect == NULL || vect[1] == NULL) {
        perror("Invalid input");
        return -1;
    }

    path = strdup(vect[1]);
    if (path == NULL) {
        perror("Memory allocation failed");
        return -1;
    }

    if (strcmp(path, arr[0]) == 0) {
		printf("path = %s", path);
		free(path);
        return chdir(dot);
    } else if (strcmp(path, arr[1]) == 0) {
		printf("path = %s", path);
		free(path);
        return chdir(parent);
    } else if (strcmp(path, arr[2]) == 0) {
		printf("path = %s", path);
		free(path);
        return chdir(previous);
    } else if (strcmp(path, arr[3]) == 0 || strcmp(path, arr[4]) == 0) {
		printf("path = %s", path);
        return chdir(home);
    } else {
		printf("path = %s", path);
        int result = chdir(path);
        free(path);
        return result;
    }
}

int main(void) {
    char *ar[] = {"cd","/home"};
    _chdir(ar);
    return 0;
}