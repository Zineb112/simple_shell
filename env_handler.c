#include "shell.h"


/**
 * _setenv add or update variables in the enviroment.
 * @env_name: variable's name.
 * @env_val: variable's value.
 * @status: check if variable value is already exist or not.
 * Return: 0 on success, -1 on error.
 */
int _setenv(const char *env_name, const char *env_val, int status)
{
	extern char **environ;
	int x = 0, length = 0;
	char *new_env_val;

	if (env_name == NULL || env_val == NULL)
	{
		return (-1);
	}
	while (environ[x])
	{
		length = _strlen(env_name);
		if (_str
	}

}

