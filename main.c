#include "main.h"

int main(__attribute__((unused)) int argc, char **argv, char **envp) {
    char *usr_input = NULL, **tokens = NULL;
    int input_stat = 0, pid = 0;
    size_t size = 1024;
    int sa = 0, status = 0, shell_stat = 0, line_counter = 0;

    while (1) {
        shell_stat = shell_prompt(), line_counter++;
        if (shell_stat == 1 || shell_stat == 0) {
            input_stat = _getline(&usr_input, &size);
            if (usr_input[0] == '\n') {
                continue;
            }
            if (input_stat == 0) {
                free(usr_input);  // Free usr_input before exit
                _exit(0);
            } else if (input_stat == -1) {
                free(usr_input);  // Free usr_input before exit
                break;
            } else {
                tokens = tokenize(usr_input);
                status = handle(tokens, &status, &sa, envp);
                free(usr_input);  // Free usr_input here
                if (status == 0) {
                    free_mem(&tokens);
                    _exit(0);
                } else if (status == -1) {
                    free_mem(&tokens);
                    exit(-1);
                } else if (status == -2) {
                    free_mem(&tokens);
                    continue;
                } else if (status > 0) {
                    free_mem(&tokens);
                    _exit(status);
                } else if (status == -3) {
                    pid = Create_process();
                    if (pid == 0) {
                        if (_execve(tokens, tokenize(_path(envp))) == -1) {
                            free_mem(&tokens);
                        }
                        Print_error(argv[0], &line_counter, tokens[0]);
                        exit(0);
                    } else if (pid > 0) {
                        free_mem(&tokens);
                        wait(NULL);
                    }
                }
            }
        }
    }
    return 0;
}