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
size_t size = 1024;
char **tokens;
int status = 0;
int com_count = 0;
int pid;


 while (1)
 { 
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    input_stat = Read_line(&usr_input,&size);
    fflush(stdin);
    fflush(stdout);
    if (input_stat == 0)
    {
        printf("eof");
        break;
    }
    else if (input_stat == -1)
   {
        printf("encountring error");
        break;
   }
    else
    {
        tokenize(usr_input,input_stat,&argv);
        fflush(stdin);
        fflush(stdout);
        pid = fork();
        if (pid == 0)
        {
            if(execvp(argv[0],argv) == -1)
            printf("command not found\n");
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