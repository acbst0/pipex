/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forpipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:29:52 by abostano          #+#    #+#             */
/*   Updated: 2023/12/26 16:28:08 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_arguments(char *argv)
{
	char	**arguments;

	arguments = ft_split(argv, ' ');
	return (arguments);
}
