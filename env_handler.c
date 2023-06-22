#include "shell.h"

/**
 * _setenv - add or update variables in the enviroment.
 * @env_name: variable's name.
 * @env_val: variable's value.
 * @status: check if variable value is already exist or not.
 * @environ_ptr: pointer to a pointer.
 * Return: 0 on success, -1 on error.
 */
int _setenv(char *env_name, char *env_val, int status, char ***environ_ptr)
{
	char **environ = *environ_ptr;
	int x = 0, length = 0;
	char *new_env_val;

	if (!env_name || !env_val)
	{
		return (-1);
	}
	while (environ[x])
	{
		length = _strlen(env_name);
		if (_strncmp(environ[x], env_name, length) == 0)
		{
			if (status)
			{
				new_env_val = malloc(_strlen(env_name) + _strlen(env_val) + 2);
				_strcpy(new_env_val, env_name);
				_strcat(new_env_val, "=");
				_strcat(new_env_val, env_val);
				environ[x] = new_env_val;
				return (0);
			}
			return (0);
		}
		x++;
	}

	new_env_val = malloc(_strlen(env_name) + _strlen(env_val) + 2);
	_strcpy(new_env_val, env_name);
	_strcat(new_env_val, "=");
	_strcat(new_env_val, env_val);
	environ[x] = new_env_val;
	environ[x + 1] = NULL;
	*environ_ptr = environ;
	return (0);
}


int main() {
	
	char **environ_ptr = "hello";
	
	char *env_name = "MY_ENV_VARIABLE";
	char *env_val = "my_value";
	int status = 1;
	
	int result = _setenv(env_name, env_val, status, &environ_ptr);
		
		if (result == 0) {
			printf("Environment variable set successfully.\n");
		} else {
			printf("Failed to set environment variable.\n");
		}
	return (0);
}

