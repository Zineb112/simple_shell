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
void _strcpy(char *desr, char *src);
int _strncmp(char *str_1, char *str_2, size_t n);


/* printing functions */
void _puts(const char *str);
int _putchar(char c);
void str_print(char *str);


/* split string functions */
char *str_tok(char* str, char* delimiters);
char **split_string(char *str, char *delimiters);

/* our getline function */
ssize_t _getline(char **line, size_t *n, FILE *stream);

/* environment variables handling */
int _setenv(char *env_name, char *env_val, int status, char ***environ_ptr);

extern char **environ;

char *_getenv(char *name);
char *getcmd(char *cmd);
char **split_string(char *buffer, char *del);
int main(int ac, char **av, char **env);

/*realloc */
void *_realloc(void *ptr, size_t size);
void *_memcpy(void *destination, const void *src, size_t size);
int _getsize(const char *str);

#endif
