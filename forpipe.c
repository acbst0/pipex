/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forpipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:45:39 by abostano          #+#    #+#             */
/*   Updated: 2024/02/14 16:56:16 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_path(char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	return (path);
}

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = ft_findpath(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error(ERR_CMD);
	}
	if (execve(path, cmd, envp) == -1)
		error(ERR_PRC);
	free(path);
}

void	error(char *er)
{
	perror(er);
	exit(1);
}

int	is_there_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			return (1);
		i++;
	}
	return (0);
}
