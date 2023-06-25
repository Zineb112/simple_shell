#include "shell.h"

/**
 * _puts - print the string.
 * @str: strings to print
 *
 * Return: nothing.
 */

void _puts(const char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
