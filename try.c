// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/wait.h>

// #define MAX_COMMAND_LENGTH 1024
// #define MAX_ARGS 64

// void execute_command(char *command) {
//     char *args[MAX_ARGS];
//     char *token;

//     // Tokenize the command
//     token = strtok(command, " \t\n");
//     int i = 0;
//     while (token != NULL) {
//         args[i++] = token;
//         token = strtok(NULL, " \t\n");
//     }
//     args[i] = NULL;

//     // Execute the command
//     pid_t pid = fork();
//     if (pid == 0) {
//         // Child process
//         execvp(args[0], args);
//         perror("execvp");
//         exit(EXIT_FAILURE);
//     } else if (pid < 0) {
//         // Error forking
//         perror("fork");
//     } else {
//         // Parent process
//         int status;
//         waitpid(pid, &status, 0);
//     }
// }

// int main() {
//     char input[MAX_COMMAND_LENGTH];

//     while (1) {
//         printf("alex@~$ ");
//         fflush(stdout);

//         // Read input from the user
//         if (fgets(input, sizeof(input), stdin) == NULL) {
//             break;
//         }

//         // Tokenize the input based on ;
//         char *command = strtok(input, ";");
//         while (command != NULL) {
//             // Execute each command
//             execute_command(command);
//             command = strtok(NULL, ";");
//         }
//     }

//     return 0;
// }