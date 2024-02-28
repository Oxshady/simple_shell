#include "main.h"

/**
 * Create_process - Creates a new process using fork
 *
 * Return: The process ID of the child process if successful, -1 on failure
 */

int Create_process(void)
{
	int pidd;

	pidd = fork();
	return (pidd);
}
