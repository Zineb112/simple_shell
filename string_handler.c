#include "shell.h"

/**
 * _strlen - get string's length.
 * @str: string.
 * Return: string's length.
 */
unsigned int _strlen(const char *str)
{
	unsigned int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}
