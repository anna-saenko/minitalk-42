/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:05:49 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/05 12:51:57 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*src_cpy;

	src_cpy = (char *)src;
	if (size <= ft_strlen(dest))
	{
		return (size + ft_strlen(src_cpy));
	}
	i = ft_strlen(dest);
	j = 0;
	while (src_cpy[j] != '\0' && i + 1 < size)
	{
		dest[i] = src_cpy[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src_cpy[j]));
}
