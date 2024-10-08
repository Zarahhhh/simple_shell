#include "shell.h"

/**
 * shell_exit - This will exit the shell.
 * @args: Arguments.
 * Return: Nothing.
 */

void shell_exit(char **args)

{
	int status = 0;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
	}
	tokens_f(args);
	input_f();
	exit(status);
}
