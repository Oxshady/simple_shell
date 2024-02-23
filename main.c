#include "main.h"

/**
 * main - simple shell
 * @argv: vector argument
 * @ac: counter argument
 * @environment: environment to find the path
 * Return: 0
 */

int main(__attribute__((unused))int argc, char **argv, char **env)
{
(void)env;
char *usr_input = NULL;
ssize_t input_stat;
size_t size;
char **tokens;
int status = 0;
int com_count = 0;
int pid;


 while (1)
 { 
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    input_stat = Read_line(&usr_input,&size);
    if (input_stat == 0)
    {
        return 0;
    }
    else if (input_stat == -1)
        break;
    else
    {
        tokenize(usr_input,input_stat,&tokens);
        pid = Create_process();
        if (pid == 0)
        {
            if(execvp(tokens[0],tokens) == -1)
            perror("command not found");
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
    }
    fflush(stdin);
    fflush(stdout);
}
}