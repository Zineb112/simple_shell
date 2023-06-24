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

char **split_string(char *str, char *delimiters)
{
	int i = 0;
	char **second_tokens;
	char *first_token = _strtok(str, delimiters);

	second_tokens = malloc(sizeof(char *) * 1024);
	while (first_token != NULL)
	{
		second_tokens[i++] = first_token;
		first_token = _strtok(NULL, delimiters);
	}
second_tokens[i] = NULL;
	return (tokens);
}

