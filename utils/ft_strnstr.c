/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:49:03 by abostano          #+#    #+#             */
/*   Updated: 2023/12/28 14:26:25 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stddef.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (*str2 == '\0')
		return ((char *)str1);
	while (str1[a] && a < n)
	{
		b = 0;
		while (str1[a + b] == str2[b] && a + b < n)
		{
			b++;
			if (str2[b] == '\0')
				return ((char *)(str1 + a));
		}
		a++;
	}
	return (0);
}
