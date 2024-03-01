#include "main.h"

/**
 * CmdFoundOrNot - Checks if a command exists and is executable
 * @argv: Argument vector
 * @command: Command to check
 * @line_counter: Pointer to line counter
 * @envp: Environment variables
 */

void CmdFoundOrNot(char **argv, char *command, int *line_counter,char **envp){
    if (access(command, X_OK) == 0)
    {
        _execve(&command, tokenize(_path(envp)));
    }
    else
    {
         Print_error(argv[0], line_counter, command);
    }
}