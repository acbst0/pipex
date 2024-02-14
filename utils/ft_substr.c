/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:30:16 by abostano          #+#    #+#             */
/*   Updated: 2024/02/12 15:28:19 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	finish;

	if (!s || !*s)
		return (ft_strdup(""));
	slen = ft_strlen(s);
	finish = 0;
	if (start < slen)
		finish = slen - start;
	if (finish > len)
		finish = len;
	if (start > slen || len == 0)
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(char) * (finish + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, finish + 1);
	return (new);
}

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}
