#include "pipex.h"

void	ft_free(char **freeable)
{
	int	a;
	
	a = 0;
	while (freeable[a] != 0)
	{
		free(freeable[a]);
		a++;
	}
	free(freeable);
}

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	int 	i;
	char	*path;
	
	i = -1;
	cmd = ft_split(argv, ' ');
	path = ft_findpath(cmd[0]);
	if (!path)	
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
