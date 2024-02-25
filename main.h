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
ssize_t Read_line(char **input, size_t *size);
char **tokenize(char *inp);
int Create_process(void);
char *_path(char **str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _execvp(char **vect);
#endif
