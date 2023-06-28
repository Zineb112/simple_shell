#include "shell.h"

/**
 * built_ins - implements  exit ,print_env builtins
 * @c_lin:   buffer command line
 * @args:   parsed ags
 * @env:   env variable
 * @exit_st:   exit status
 * Return: void
 */
void built_ins(char *c_lin, char **args, char **env, int *exit_st)
{

	if (str_cmp(args[0], "exit") == 0)
	{
		free(args);
		free(c_lin);
		exit(*exit_st);
	}

	if (str_cmp(args[0], "env") == 0)
		print_env(env, exit_st);
}

/**
 * exec_env - executed in   main
 * @status:   status of   path,if   file is executable
 * @args:  parsed args
 * @exit_st:   exit status
 * @taly: tally of commands or attempted commands that were run
 * Return: void
 */
void exec_env(int status, char **args, int *exit_st, int *taly)
{
	if (status == 2)
	{
		if (access(args[0], X_OK) == 0)
		{
			if (fork() == 0)
				execve(args[0], args, NULL);

			else
				wait(NULL);
			*exit_st = 0;
		}
		else if (access(args[0], F_OK) != 0)
		{
			printstr_("sh: ");
			print_int(taly);
			printstr_(": ");
			perror(args[0]);
			*exit_st = 127;
		}
		else if (access(args[0], F_OK) == 0 && access(args[0], X_OK) != 0)
		{
			printstr_("sh: ");
			print_int(taly);
			printstr_(": ");
			perror(args[0]);
			*exit_st = 126;
		}
	}
	free(args);
}


