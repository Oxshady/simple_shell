#include "main.h"
int setenv_unset(char **vect,int val)
{
	char *line = NULL;
    char *VARNAME = NULL;
    char *VALUE = NULL;
    if (vect == NULL || vect[1] == NULL) {
        printf("Invalid input\n");
        return -1;
    }
	line = strdup(vect[1]);
	VARNAME = strtok(line, "=");
    if (VARNAME == NULL) {
        printf("Invalid input\n");
        return -1;
    }
	if (val == 3)
	{
		if (unsetenv(VARNAME) == 0)
        {
		    printf(" variable %s unsettt",VARNAME);
            free(line);
        }
        return(4);
	}
	
    VALUE = strtok(NULL, "");

    if (VALUE[0] == '"' && VALUE[strlen(VALUE) - 1] == '"') {
        VALUE[strlen(VALUE) - 1] = '\0';
        VALUE++;
    }

    if (setenv(VARNAME, VALUE, 0) == 0) {
        printf("Environment variable %s set to %s\n", VARNAME, VALUE);
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