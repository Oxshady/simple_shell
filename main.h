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
int shell_prompt(void);
char **tokenize(char *inp);
int Create_process(void);
char *_path(char **str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _execve(char **vect,char **paths);
void _get_env(char **en);
int _getline(char **inp, size_t *size);
int setenv_unset(char **vect,int val);
int _atoi(char *s);
int _parent(char **pare);
int _chdir(char **vect)
#endif

