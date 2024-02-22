#include "main.h"

/**
* main - simple shell
* @argv: vector argument
* @ac: counter argument
* @environment: environment to find the path
* Return: 0
*/

int main(int argc, char argv, char env)
{
(void)argc;
char *usr_input = NULL;
ssize_t input_stat;
size_t size = 1024;
char tokens;
int status = 0;
int com_count = 0;


 while (1)
 { 
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    input_stat = Read_line(&usr_input,&size);
}
}
