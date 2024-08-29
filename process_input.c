#include "shell.h"

/**
 * process_input - Processes the user input.
 * @input: The user input to process.
 * Executes the command if it is not "exit", otherwise exits the shell.
 */

void process_input(char *input)

{
	if (strcmp(input, "exit") == 0)
	{
		exit(0);
	}
	execute_command(input);
}
