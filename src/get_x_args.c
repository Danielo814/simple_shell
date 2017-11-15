#include "holberton.h"

char *get_x_args(char **env_paths, char *program)
{
	int i = 1;
	int pCount = strlen(program);
	int pathCount;
	char *tmp;

	pathCount = strlen(env_paths[0]);
	tmp = malloc(sizeof(char) * (strlen(env_paths[0]) + pCount) + 2);
	if (tmp == NULL)
		perror("grosse alert la...alert rouge, segfult!: "), exit(EXIT_FAILURE);
	
	tmp = memset(tmp, 0, (pathCount + pCount) + 2);
	strcpy(tmp, env_paths[0]);
	strcat(tmp, "/");
	strcat(tmp, program);

	while (access(tmp, X_OK) == -1 && env_paths[i] != NULL)
	{
		pathCount = strlen(env_paths[i]);
		tmp = realloc(tmp, sizeof(char) * (pathCount + pCount) + 2);
		if (tmp == NULL)	
			perror("gros gros segfult: "), exit(EXIT_FAILURE);

		tmp = memset(tmp, 0, (pathCount + pCount) + 2);
		strcpy(tmp, env_paths[i]);
		strcat(tmp, "/");
		strcat(tmp, program);
		/* printf("[inloop: %s]\n", tmp); */
		i++;
	}
	if (env_paths[i] == NULL)
	{
		/* rintf("heyaa"); */
		return (NULL);
	}
	else
		return (tmp);
}
