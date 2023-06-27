#include "shell.h"

/**
 * _getenv - get variables from the enviroment.
 * @env_name: variable's name.
 * Return: NULL.
 */
char *_getenv(char *env_name)
{
	int x;
	char *key;

	x = 0;
	while (environ[x])
	{
		key = str_tok(environ[x], "=");
		if (_strcmp(env_name, key) == 0)
		{
			return (str_tok(NULL, "\n"));
		}
		x++;
	}
	return (NULL);
}
