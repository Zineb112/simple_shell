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

/* read - write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define TRUE (1 == 1)

/* my_path function*/
int my_path(char *xfirst, char **inpt, char **env, int *exit_st);


/* env function */
int print_env(char **env, int *exit_st);
char *cpy_env(char **env);

/* built- execute functions */
void built_ins(char *c_lin, char **args, char **env, int *exit_st);
void exec_env(int status, char **args, int *exit_st, int *taly);

/* strings  functions */
int str_len(char *s);
char *str_dup(char *strg);
int str_cmp(char *str1, char *str2);
char *str_cpy(char *dstn, char *sourc);
char *str_cat(char *dstn, char *sourc);
int put_char(char ch);
void printstr_(char *st);
char *path_str(char *p_right, char *xfirst);
char **_parser(char *l);
void print_int(int *taly);


/* o r functions */
void no_nul(char *l);
void grid_free(char **gridd, int _height);
int char_special(char *buffer, ssize_t byt, int *exit_st);

ssize_t _getline(char **line, size_t *n, FILE *stream);
char *str_tok(char *str, const char *delimiters);
void *_realloc(void *ptr, size_t size);
void *_memcpy(void *destination, const void *src, size_t size);
int _getsize(const char *str);
void _puts(const char *str);
int _putchar(char c);

/*setenv unsetenv*/
void _setenv(char **arr);
void _unsetenv(char **arr);
char *get_env(const char *glob_v);
char *concatenat(char *glob_v, char *valeur1, char *valeur);

extern char **environ;

#endif

