#include "main.h"
pid_t Create_process(void)
{
	pid_t pidd;

	pidd = fork();

	return pidd;
}