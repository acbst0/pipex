/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:27:25 by abostano          #+#    #+#             */
/*   Updated: 2023/12/22 17:31:37 by abostano         ###   ########.fr       */
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

char	**ft_args(char	**argv)
{
	int		i;
	int		a;
	char	**args;

	a = 0;
	while (argv[a + 1] != "|")
		a++;
	//*args = malloc(sizeof(char) * a + 1);
	args[a] = NULL;
	i = 1;
	while (argv[i] != "|")
	{
		args[i - 1] = argv[i];//ft_strdup(argv[i]);
		i++;
	}
	return (args);
}

int	main(int argc, char **argv)
{
	//char		*args[] = {argv[1], argv[2], argv[3], argv[4]}
	char	**args;
	args = ft_args(argv);

	execve(ft_findpath(argv[1]), args, NULL);
	int i = 0;
	/*
	while (args[i] != NULL)
	{
  	  free(args[i]);
 	   i++;
	}
	free(args);
	*/
}