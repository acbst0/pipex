/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:27:25 by abostano          #+#    #+#             */
/*   Updated: 2023/12/26 17:16:29 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_findpath(char *command)
{
    char **paths;
    char *path;
    char *tmp;
    int i;

	
    paths = ft_split(getenv("PATH"), ':');
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
//Child PID
void	ft_childpid(int pipefd[], char *argv[], char *env[])
{
	int	f1;

	f1 = open(argv[1], O_RDONLY, 0777);
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(f1, STDIN_FILENO);
	close(pipefd[0]);
	ft_execute(argv[2], env);
}
//Parent PID
void	ft_parentpid(int pipefd[], char *argv[], char *env[])
{
	int	f2;

	f2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC , 0777);
	if (f2 == -1)
		return 0;
	dup2(pipefd[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(pipefd[1]);
	ft_execute(argv[3], env);
}

int	main(int argc, char *argv[], char *env[])
{
	pid_t		child_pid;
	int			pipefd[2];

	pipe(pipefd);
	child_pid = fork();
	if (child_pid == 0)
	{
		ft_childpid(pipefd, argv, env);
	}
	else
	{
		waitpid(child_pid, NULL, 0);
		ft_parentpid(pipefd, argv, env);
	}

	write(1, "free\n", 2);
}