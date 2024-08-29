#include "shell.h"

/**
 * sigint_h - This handles signal for SIGINT (Ctrl+C).
 * @sig: Signal number.
 * Return: Nothing.
 */

void sigint_h(int sig)

{
	(void) sig;
	putchar('\n');
	myprompt();
}

/**
 * sigquit_h - Handles signal for SIGQUIT (Ctrl+\).
 * @sig: Signal number.
 * Return: Nothing.
 */

void sigquit_h(int sig)

{
	(void) sig;
	perror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * sigstp_h -  Handle signal for SIGTSTP (Ctrl+Z)
 * @sig: Signal number
 * Return: 0
 */

void sigstp_h(int sig)

{
	(void) sig;
	puts("\n");
	myprompt();
}
