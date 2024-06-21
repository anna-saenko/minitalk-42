/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:19:09 by asaenko           #+#    #+#             */
/*   Updated: 2024/02/27 10:39:07 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	len;
	char	*src_cpy;

	len = 0;
	src_cpy = (char *)src;
	if (!dest)
	{
		return (0);
	}
	len = ft_strlen(src_cpy);
	if (!destsize)
	{
		return (len);
	}
	while (--destsize && *src_cpy)
	{
		*dest++ = *src_cpy++;
	}
	*dest = '\0';
	return (len);
}
