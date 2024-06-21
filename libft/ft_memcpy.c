/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:16:32 by asaenko           #+#    #+#             */
/*   Updated: 2024/02/20 15:16:42 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t				i;
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	i = 0;
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	while (i < count)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}
