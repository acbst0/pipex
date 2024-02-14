/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:27:28 by abostano          #+#    #+#             */
/*   Updated: 2024/02/14 17:07:31 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define ERR_INFILE "Infile Error"
# define ERR_OUTFILE "Outfile Error"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_PATH "Path not found\n"
# define ERR_CMD "Command not found\n"
# define ERR_PRC "The process failed\n"

char	**ft_split(const char *s, char c);
char	*ft_findpath(char *command, char *envp[]);
char	*ft_strjoin(const char *str1, const char *str2);
size_t	ft_strlen(const char *a);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_free(char **freeable);
void	ft_execute(char *argv, char **envp);
char	*ft_path(char *envp[]);
void	error(char *er);
int		msg(char *err);
int		is_there_path(char *envp[]);

#endif
