#include "shell.h"

char *_getenv(const char *name)
{
        extern char **environ;
        int x = 0;
        char *key;

        while (environ[x])
        {
                key = strtok(environ[x], "=");
                if (strcmp(name, key) == 0)
                {
                        return (strtok(NULL, "\n"));
                }
                x++;
        }
        return (NULL);
}

char *getcmd(char *cmd)
{
        char *path = _getenv("PATH");
        char *token;
        char *cmd_path;
        struct stat st;

        token = strtok(path, ":");
	while (token)
	{
		cmd_path = malloc(strlen(token) + strlen(cmd) + 2);
		strcpy(cmd_path, token);
		strcat(cmd_path, "/");
		strcat(cmd_path, cmd);
		if (stat(cmd_path, &st) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}

char **split_string(char *buffer, char *del)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	token = strtok(buffer, del);
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}


int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *cmd;
	char **args;
	pid_t pid;
	int status, n_chars;
	int i = 0;
	const char *msg = "Command not found";


	while (1)
	{
		write(1, "$ ", 2);
		n_chars = getline(&buffer, &buffer_size, stdin);
		if (n_chars == -1)
		{
			write(1, "\n", 1);
			exit(1);
		}
		args = split_string(buffer, " \t\n");
		if (strcmp(args[0], "exit") == 0)
			exit(0);
		pid = fork();
		if (pid == 0)
		{
			cmd = getcmd(args[0]);
			if (cmd)
				execve(cmd, args, env);
			else
				while (msg[i] != '\0')
				{
					_putchar(msg[i]);
					i++;
				}
			_putchar('\n');
			exit(0);
		}
		else
			wait(&status);
	}
	
	return (0);
}



