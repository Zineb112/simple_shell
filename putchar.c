#include "shell.h"

/**
 * _putchar - writes string to stdout
 * @c: string to print
 *
 * Return: On success 1.
 * On error -1.
 */
int _putchar(char c)
{
		return (write(1, &c, 1));
}

/**
 * str_print - use putchar to print a string.
 * @str: string to pring.
 */
void str_print(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}
