#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#ifndef MAIN_H
#define MAIN_H
ssize_t Read_line(char **input, size_t *size);
void tokenize(char *inp, int size);
char **vector = NULL;
#endif
