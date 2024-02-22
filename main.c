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
char *usr_input;
ssize_t input_stat;
size_t size = 1024;
char **tokens;
int status = 0;
int com_count = 0;

while (1)
{

<<<<<<< HEAD
user_input  = Read_line()

if (user_input == 2)
=======
input_stat = Read_line(&usr_input,&size);
if (input_stat == 2)
>>>>>>> 317505fc0c118115240f1ff337cbf47a74e8f216
{
    if (isatty(STDIN_FILENO))
{
    write(STDOUT_FILENO, "$ ", 2);
}
return (status);
}
com_count++;

// tokens = _strtok(user_input)

if (!tokens)
{
continue;
}

/*
 enviromet path
 chek the command in the path or not
 exce the command
*/

}
}
