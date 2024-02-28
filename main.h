#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
extern char **__environ;
int shell_prompt(void);
char **tokenize(char *inp);
pid_t Create_process(void);
char *_path(char **str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _execve(char **vect, char **paths);
void _get_env(char **en);
size_t _getline(char **inp, size_t *size);
int setenv_unset(char **vect, int val);
int _atoi(char *s);
int _parent(char **pare);
int _chdir(char **vect);
int _exitt(char **vect);
void Print_error(char *argv, int *counter_line, char *command);
char *_itoa(int num);
void revstr(char *buf, int i);
char *createCommandPath(char *path, char *command);
int executeWithPath(char **vect);
int executeFromPaths(char **vect, char **paths);
int containsSlash(char *str);
int _execve(char **vect, char **paths);
void execute_command(char **tokens, char **argv, int *line_counter, char **envp);
int shell_loop(char **argv, char **envp);
#endif

