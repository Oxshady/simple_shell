#include "main.h"

void Print_error(char *argv, int *counter_line, char *command)
{
    write(STDIN_FILENO, argv, _strlen(argv));
    write(STDIN_FILENO, ": ", 2);
    write(STDIN_FILENO, counter_line, _strlen(counter_line));
    write(STDIN_FILENO, ": ", 2);
    write(STDIN_FILENO, command, _strlen(command));
    write(STDIN_FILENO, ": not found", 11);
}
