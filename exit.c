#include "main.h"

void _exitt(char **input)
{
    char *x = "exit";
    char **asd;
    int i = 0;
    int y = 0;

    if(strncmp(input, x, 4) == 0)
    {
        asd[i] = strdup(strtok(input, " "));
        while (asd != NULL)
        {
            asd[i] = strdup(strtok(NULL, " "));
            i++;
        }
        y = _atoi(asd[1]);
        _exit(y);
        free(asd);
    } 
}
int main(void)
{
    char **input;
    scanf(&input);
}