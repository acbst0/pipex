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

	//getenv("PATH");
    paths = ft_split("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki", ':');
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
void	ft_childpid(int pipefd[], char *argv[], char *args[])
{
	close(pipefd[0]);
	pipefd[0] = open(argv[1], O_RDONLY, 0777);
	dup2(pipefd[0], 0);
	close(pipefd[1]);

	execve(ft_findpath(args[0]), args, NULL);
}
//Parent PID
void	ft_parentpid(int pipefd[], char *argv[], char *args[])
{
	close(pipefd[1]);
	pipefd[1] = open(argv[4], O_RDONLY | O_TRUNC , 0777);
	dup2(pipefd[1], 0);
	close(pipefd[0]);

	execve(ft_findpath(args[0]), args, NULL);
}

int	main(int argc, char *argv[], char *env[])
{
	pid_t		child_pid;
	int			pipefd[2];
	char		**args;

	pipe(pipefd);
	child_pid = fork();
	if (child_pid == 0)
	{
		args = ft_arguments(argv[2]);
		ft_childpid(pipefd, argv, args);
	}
	else
	{
		free(args);

		int	*status;

		waitpid(child_pid, status, 0);
		ft_parentpid(pipefd, argv, args);
	}
}