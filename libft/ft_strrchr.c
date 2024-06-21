/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:03:03 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/05 12:53:59 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*s_cpy;

	res = NULL;
	s_cpy = (char *)s;
	while (*s_cpy)
	{
		if (*s_cpy == (char)c)
		{
			res = (char *)s_cpy;
		}
		s_cpy++;
	}
	if (*s_cpy == '\0' && c == '\0')
		return ((char *)s_cpy);
	return (res);
}
