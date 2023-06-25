#include "shell.h"

/**
 * _strtok - split string.
 * @str: string to split.
 * @delimiters: separator.
 * Return: splited strings.
 */
char *_strtok(char *str, const char *delimiters)
{
	static char *token1;
	static char *tokens;

	if (str != NULL)
	{
		token1 = str;
	}
	else if (tokens == NULL)
	{
		return (NULL);
	}
	else
	{
		token1 = tokens;
	}

	char *delim_pos = token1;

	while (*delim_pos != '\0')
	{
		if (*delim_pos == *delimiters)
		{
			*delim_pos = '\0';
			tokens = delim_pos + 1;
			return (token1);
		}
		delim_pos++;
	}
	tokens = NULL;

	return (token1);
}


/**
 * split_string - check code.
 * @str: string to split.
 * @delimiter: charactaer.
 * Return: splited string.
 */
char **split_string(char *str, char *delimiter)
{
	char **ptr_token;
	char *token;
	int i = 0;

	ptr_token = malloc(sizeof(char *) * 1024);
	token = strtok(str, delimiter);
	while (token)
	{
		ptr_token[i] = token;
		token = strtok(NULL, delimiter);
		i++;
	}
	ptr_token[i] = NULL;
	return (ptr_token);
}


