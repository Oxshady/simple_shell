#include "main.h"
int shell_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
        write(STDOUT_FILENO, "$ ", 2);
		return (1);
	}
	else
		return(0);
}