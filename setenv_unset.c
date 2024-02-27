#include "main.h"
int setenv_unset(char **vect,int val)
{
	char *line = NULL;
    char *varName = NULL;
    char *value = NULL;
    if (vect == NULL || vect[1] == NULL) {
        printf("Invalid input\n");
        return -1;
    }
	line = strdup(vect[1]);
	varName = strtok(line, "=");
    if (varName == NULL) {
        printf("Invalid input\n");
        return -1;
    }
	if (val == 3)
	{
		if (unsetenv(varName) == 0)
        {
		    printf(" variable %s unsettt",varName);
            free(line);
        }
        return(4);
	}
	
    value = strtok(NULL, "");

    if (value[0] == '"' && value[strlen(value) - 1] == '"') {
        value[strlen(value) - 1] = '\0';
        value++;
    }

    if (setenv(varName, value, 0) == 0) {
        printf("Environment variable %s set to %s\n", varName, value);
    } else {
        perror("setenv");
        return -1;
    }

    return 0;
}

int main(void)
{
	char *ve[3] = {"export","MY_VAR=\"HOME\""};
	setenv_unset(ve,3);
	return 0;
}