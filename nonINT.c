#include "main.h"

/**
* handle_command - function that handle the non interactive scripts(commands)
* @tokens: tokenized commands
* @envp: env variables
* @line: line counter
* @argv: file name for errors
*/
void handle_command(char **tokens, char **envp, int line, char *argv)
{
int found = 0;
char *path_copy = NULL;
char *path_token = NULL;
char *path = getenv("PATH");

if (path == NULL)
{fprintf(stderr, "PATH environment variable not found\n");
exit(EXIT_FAILURE);
}
path_copy = strdup(path);
if (path_copy == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
path_token = strtok(path_copy, ":");
while (path_token != NULL)
{char *command_path = NULL;
if (strcmp(tokens[0], "/") == 0)
{command_path = strdup(tokens[0]);
}
else
{
size_t path_len = strlen(path_token), size_t token_len = strlen(tokens[0]);
command_path = malloc(path_len + token_len + 2);
if (command_path == NULL)
{perror("malloc");
exit(EXIT_FAILURE);
}
snprintf(command_path, path_len + token_len + 2, "%s/%s", path_token, tokens[0]);
}
if (access(command_path, X_OK) == 0)
{
if (execve(command_path, tokens, envp) == -1)
{perror("execve"), free(command_path);
exit(EXIT_FAILURE);
}
found = 1;
break;
}
free(command_path), path_token = strtok(NULL, ":");
}
free(path_copy);
if (!found)
{Non_Print_error(argv, &line, tokens[0]);
exit(EXIT_FAILURE);
}
}
