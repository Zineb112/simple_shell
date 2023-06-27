#include "shell.h"
#define _ISOC99_SOURCE

/**
 * getcmd - get cmd that user enter.
 * @cmd: the command line.
 * Return: NULL.
 */
char *getcmd(char *cmd)
{
	char *path;
	char *token;
	char *cmd_path;
	struct stat st;

	path = _getenv("PATH");
	token = strtok(path, ":");
	while (token)
	{
		cmd_path = malloc(_strlen(token) + _strlen(cmd) + 2);
		_strcpy(cmd_path, token);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd);

		if (stat(cmd_path, &st) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}


/**
 * main - check code.
 * @ac: first argument.
 * @av: second argument.
 * @env: environment variables.
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	size_t buffer_size;
	char *cmd, **arg, *buffer, *msg;
	pid_t pid;
	int check, chars_num;
	(void)ac;
	(void)av;
	(void)env;
	buffer = NULL;
	buffer_size = 0;
	msg = "This command does not exist\n";

	while (1)
	{
		write(1, "$ ", 2);
		chars_num = _getline(&buffer, &buffer_size, stdin);
		if (chars_num == -1)
		{
			write(1, "\n", 1);
			exit(1);
		}
		arg = split_string(buffer, " \t\n");
		if (_strcmp(arg[0], "exit") == 0)
			exit(0);
		pid = fork();
		if (pid == 0)
		{
			cmd = getcmd(arg[0]);
			if (cmd)
				execve(cmd, arg, NULL);
			else
				str_print(msg);
			exit(0);
		}
		else
			wait(&check);
	}

	return (0);
}
