/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:27:25 by abostano          #+#    #+#             */
/*   Updated: 2024/02/14 16:57:38 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_findpath(char *command, char *envp[])
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	paths = ft_split(ft_path(envp), ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, command);
		if (access(path, X_OK) == 0)
			return (path);
		free(tmp);
		i++;
	}
	return (NULL);
}

void	ft_childpid(int pipefd[], char *argv[], char *env[])
{
	int	f1;

	f1 = open(argv[1], O_RDONLY, 0644);
	if (f1 == -1)
		error(ERR_INFILE);
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(f1, STDIN_FILENO);
	close(pipefd[0]);
	ft_execute(argv[2], env);
}

void	ft_parentpid(int pipefd[], char *argv[], char *env[])
{
	int	f2;

	f2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (f2 == -1)
		error(ERR_OUTFILE);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(pipefd[1]);
	ft_execute(argv[3], env);
}

int	main(int argc, char *argv[], char *env[])
{
	pid_t		child_pid;
	int			pipefd[2];

	if (is_there_path(env) == 0)
		error(ERR_PATH);
	if (argc == 5)
	{
		if (pipe(pipefd) == -1)
			error(ERR_PIPE);
		child_pid = fork();
		if (child_pid == -1)
			error(ERR_PRC);
		if (child_pid == 0)
			ft_childpid(pipefd, argv, env);
		ft_parentpid(pipefd, argv, env);
	}
	else
	{
		msg(ERR_INPUT);
	}
	return (0);
}
