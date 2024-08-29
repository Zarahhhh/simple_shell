#include "shell.h"

/**
	* find_command_path - Searches for the command in directories listed in PATH.
	* @cmd: The command to search for.
	* Return: The full path of the command if found, NULL otherwise.
	*/

char *find_command_path(const char *cmd)

{
	char *path_env = getenv("PATH");

	if (!path_env)
		return (NULL);

	char *path = strdup(path_env);
	char *dir = strtok(path, ":");

	while (dir)
	{
		char full_path[MAX_PATH_SIZE];

		snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (strdup(full_path));
		}
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
