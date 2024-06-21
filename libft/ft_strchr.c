/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:20 by asaenko           #+#    #+#             */
/*   Updated: 2024/02/27 13:49:22 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s_cpy;

	s_cpy = (unsigned char *)s;
	while (*s_cpy)
	{
		if (*s_cpy == (unsigned char)c)
		{
			return ((char *)s_cpy);
		}
		s_cpy++;
	}
	if (*s_cpy == '\0' && (unsigned char)c == '\0')
		return ((char *)s_cpy);
	return (NULL);
}
