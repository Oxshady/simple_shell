#include "main.h"

int handle(char **token, int *status,int *sa,char **envp)
{
	char buffer[20];

	if (strcmp(token[0], "exit") == 0)
	{
		*status = _exitt(token);
		if (*status == 0)
			return (0);
		else if (*status > 0)
		{
		int length = sprintf(buffer, "%d\n",*status);
		write(STDOUT_FILENO, buffer, length);
		return (*status);
		}
		else if(*status = -1)
			return (-1);
	}
	else if(strcmp(token[0],"export") == 0){
		*sa = 0, setenv_unset(token,*sa);
		return -2;
	}
	else if(strcmp(token[0],"unset") == 0)
	{
		*sa = 1, setenv_unset(token,*sa);
		return -2;
	}
	else if(strcmp(token[0],"cd") == 0)
	{
		_chdir(token);
		return -2;
	}
	else if(strcmp(token[0],"env") == 0)
	{
		_get_env(envp);
		return -2;
	}
}