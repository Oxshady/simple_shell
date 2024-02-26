#include "main.h"

/**
 * main - simple shell
 * @argv: vector argument
 * @ac: counter argument
 * @environment: environment to find the path
 * Return: 0
 */

int main(__attribute__((unused))int argc, char **argv, char **envp)
{
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
    input_stat = Read_line(&usr_input,&size);
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
        pid = Create_process();
        if (pid == 0)
        {
            if(_execve(tokens,tokenize(_path(envp))) == -1);
                perror("command not found");
            exit(0);
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
    }
    fflush(stdin);
    fflush(stdout);
    }
    else
        return -1;
}
}