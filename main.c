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
char *usr_input = NULL;
ssize_t input_stat;
size_t size = 1024;
char **tokens;
int status = 0;
int com_count = 0;


 while (1)
 { 
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    input_stat = Read_line(&usr_input,&size);
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
        printf("read line successfull\n");
        tokenize(usr_input,input_stat,&argv);
        printf("tokens done\n");
        printf("token 1 %s\n",argv[0]);
        printf("token 2 %s\n",argv[1]);
        printf("tokens is done suucc\n");
    }
}
}