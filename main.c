#include "main.h"

/**
* main - Simple shell
* @argc: Argument count
* @argv: Argument vector
* @envp: Environment variables
* Return: Always 0
*/

int main(__attribute__((unused)) int argc, char **argv, char **envp)
{char *usr_input = NULL, **tokens = NULL;
int input_stat = 0, pid = 0;
size_t size = 0;
int sa = 0, status = 0, shell_stat = 0, line_counter = 0;

while (1)
{shell_stat = shell_prompt(), line_counter++;
if (shell_stat == 1)
{
input_stat = _getline(&usr_input, &size);
if (usr_input[0] == '\n')
continue;
if (input_stat == 0)
_exit(0);
else if (input_stat == -1)
break;
else
{tokens = tokenize(usr_input), status = handle(tokens, &status, &sa, envp);
if (status == 0 || status == -1)
_exit(0);
else if (status == -2)
continue;
else if (status > 0)
_exit(status);
else if (status == -3)
{pid = Create_process();
if (pid == 0)
{
	if (_execve(tokens, tokenize(_path(envp))) == -1)
{};
Print_error(argv[0], &line_counter, tokens[0]);
exit(0);
}
else if (pid > 0)
wait(NULL);
}}}
else
return (-1);
}
return (0);
}
