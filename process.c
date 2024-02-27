#include "main.h"

/**
 * Create_process - Creates a new process using fork
 *
 * Return: The process ID of the child process if successful, -1 on failure
 */

pid_t Create_process(void)
{
	pid_t pidd;

	pidd = fork();
	return (pidd);
}
