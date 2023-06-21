#include "shell.h"
#include <unistd.h>

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
