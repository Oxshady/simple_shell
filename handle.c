#include "main.h"
/**
 * handle - this func handle builtin commands
 * @tokens: tokens
 * @status: state of cmd
 * @sa: to determine setenv stat
 * @envp: enviroment var
 * Return: stat
*/
int handle(char **tokens, int *status, int *sa, char **envp)
{
if (strcmp(tokens[0], "exit") == 0)
{
*status = _exitt(tokens);
if (*status == 0)
return (0);
else if (*status > 0)
{
return (*status);
}
else if (*status < 0)
return (100);
}
else if (strcmp(tokens[0], "export") == 0)
{
sa = 0;
setenv_unset(tokens, *sa);
return (-2);
}
else if (strcmp(tokens[0], "unset") == 0)
{
*sa = 1, setenv_unset(tokens, *sa);
return (-2);
}
else if (strcmp(tokens[0], "cd") == 0)
{
_chdir(tokens);
return (-2);
}
else if (strcmp(tokens[0], "env") == 0)
{
_get_env(envp);
return (-2);
}
else
return (-3);
return (-3);
}
