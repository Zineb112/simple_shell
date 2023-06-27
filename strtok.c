#include "shell.h"

/**
 * str_tok - split string.
 * @str: string to split.
 * @delim: separator.
 * Return: splited strings.
 */
char *str_tok(char str[], char *delim)
{
	static char *split_ted, *end_str;
	char *start_str;
	unsigned int i, bol;

	if (str != NULL)
	{
		if (!_strcmp(str, delim))
			return (NULL);
		split_ted = str;
		i = strlen(str);
		end_str = &str[i];
		printf("%s\n", str);
	}
	start_str = split_ted;
	if (start_str == end_str)
		return (NULL);

	for (bol = 0; *split_ted && split_ted != end_str; split_ted++)
	{
		if (split_ted != start_str)
			if (*split_ted && *(split_ted - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*split_ted == delim[i])
			{
				*split_ted = '\0';
				if (split_ted == start_str)
					start_str++;
				break;
			}
		}
		if (bol == 0 && *split_ted)
			bol = 1;
	}
	if (bol == 0)
		return (NULL);
	return (start_str);
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


