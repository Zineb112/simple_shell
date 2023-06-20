#ifndef _shell_h
#define _shell_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Strings handling function */
unsigned int _strlen(const char *str);
void _strcat(char *str_1, char *str_2);
int _strcmp(char *str_1, char *str_2);
#endif
