#include "shell.h"

/**
 * execute_command - Executes the command if it exists.
 * @cmd: The command to execute.
 * Calls fork() to create a new process and execve() to run the command.
 * Prints an error message if the command does not exist.
 */

void execute_command(const char *cmd)

{
	char *cmd_path = find_command_path(cmd);

	if (cmd_path)

	{
		pid_t pid = fork();

		if (pid == 0)

		{
			execl(cmd_path, cmd, NULL);
			perror("execl");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			wait(NULL);
		}
		free(cmd_path);
	}
	else
	{
		fprintf(stderr, "%s: command not found\n", cmd);
	}
}
