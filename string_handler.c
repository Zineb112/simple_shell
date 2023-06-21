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


/**
 * _strcat - concatenates two strings.
 * @str_1: the last string will be stored here.
 * @str_2: the string to be appended
 */
void _strcat(char *str_1, char *str_2)
{
	while (*str_1 != '\0')
	{
		str_1++;
	}

	while (*str_2 != '\0')
	{
		*str_1 = *str_2;
		str_1++;
		str_2++;
	}


	*str_1 = '\0';
}

/**
 * _strcmp - compare two strings.
 * @str_1: First string.
 * @str_2: second string.
 * Return: 0 if the strings are equal, o
 * therwis somthing else.
 */
int _strcmp(char *str_1, char *str_2)
{
	while (*str_1 != '\0' && *str_2 != '\0')
	{
		if (*str_1 != *str_2)
		{
			return (*str_1 - *str_2);
		}

		str_1++;
		str_2++;
	}
	return (*str_1 - *str_2);
}



/**
 * _strncmp - compare n characters of two given strings.
 * @str_1: First string.
 * @str_2: second string.
 * @n: the maximum number of characters to compare.
 * Return: 0 if the strings are equal, o
 * therwis somthing else.
 */
int _strncmp(char *str_1, char *str_2, size_t n)
{
	while (n > 0 && *str_1 != '\0' && *str_2 != '\0')
	{
		if (*str_1 != *str_2)
		{
			return (*str_1 - *str_2);
		}

		str_1++;
		str_2++;
		n--;
	}

	if (n == 0)
	{
		return (0);
	}

	return (*str_1 - *str_2);
}



/**
 * _strcpy - copy a string to another.
 * @dest: string 1.
 * @src: string 2.
 */
void _strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
