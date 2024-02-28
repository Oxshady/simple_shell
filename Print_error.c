#include "main.h"

/**
 * Print_error - Print error message
 * @argv: Argument vector
 * @counter_line: Pointer to counter line
 * @command: Command
 */

void Print_error(char *argv, int *counter_line, char *command)
{
char *ptr = NULL;
ptr = _itoa(*counter_line);
write(STDIN_FILENO, argv, _strlen(argv));
write(STDIN_FILENO, ": ", 2);
write(STDIN_FILENO, ptr, strlen(ptr));
write(STDIN_FILENO, ": ", 2);
write(STDIN_FILENO, command, _strlen(command));
write(STDIN_FILENO, ": not found", 11);
write(STDOUT_FILENO, "\n", 2);
}
