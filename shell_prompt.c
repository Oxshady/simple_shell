#include "main.h"

/**
 * shell_prompt - Displays a prompt if stdin is a terminal
 *
 * Return: 1 if stdin is a terminal, 0 otherwise
 */

int shell_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		return (1);
	}
	else
		return (0);
}
