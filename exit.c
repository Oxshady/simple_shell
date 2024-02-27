#include "main.h"

int _exitt(char **vect)
{
    if (vect == NULL || vect[0] == NULL)
        return 3; 

    char *x = "exit";
    int exit_code = 0;

    if (strncmp(vect[0], x, strlen(x)) == 0)
    {
        if (vect[1] != NULL)
        {
            exit_code = atoi(vect[1]);
            return exit_code; 
        }
        else
            return 0; 
    }

    return 3; 
}
int main(__attribute__((unused))int argc, char **argv, char **envp)
{
    int n;
char *usr_input = NULL;
ssize_t input_stat;
size_t size;
char **tokens = NULL;
int status = 0;
int com_count = 0;
int pid;
int shell_stat;
char *pa = NULL;
char **p;
 while (1)
 { 
    shell_stat = shell_prompt();
    if (shell_stat == 1)
    {
    input_stat = _getline(&usr_input,&size);
    if (usr_input[0] == '\n')
        continue;
    if (input_stat == 0)
    {
        return 0;
    }
    else if (input_stat == -1)
        break;
    else
    {
        tokens =  tokenize(usr_input);
      n = _exitt(tokens);
      char buffer[20]; 
    int length = sprintf(buffer, "%d\n", n);
    write(STDOUT_FILENO, buffer, length);
      if (n != 3)
        _exit(n);

    }
    fflush(stdin);
    fflush(stdout);
    }
    else
        return -1;
}
}