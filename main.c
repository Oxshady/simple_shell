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
int status = 0; //////// -> unused
int line_counter = 0; //// 
pid_t pid;
int shell_stat;
char *pa = NULL;
char **p;
char buffer[20]; 
int sa;

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
        _exit(0);
    }
    else if (input_stat == -1)
        break;
    else
    {
        // export --> setenv
        // unset --> unsetenv var
        // cd --> change dir
        //exit --> exit from the main
        tokens =  tokenize(usr_input);
        if (strcmp(tokens[0], "exit") == 0)
        {
            status = _exitt(tokens);
            if (status == 0)
                _exit(0);
            else if (status > 0)
            {
            int length = sprintf(buffer, "%d\n",status);
            write(STDOUT_FILENO, buffer, length);
            _exit(status);
            }
            else if(status = -1)
                _exit(-1);
        }
        else if(strcmp(tokens[0],"export") == 0){
            sa = 0;
            setenv_unset(tokens,sa);
            continue;
        }
        else if(strcmp(tokens[0],"unset") == 0)
        {
            sa = 1;
            setenv_unset(tokens,sa);
            continue;
        }
        else if(strcmp(tokens[0],"cd") == 0)
        {
            _chdir(tokens);
            continue;
        }
        else if(strcmp(tokens[0],"env") == 0)
        {
            _get_env(envp);
            continue;
        }
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