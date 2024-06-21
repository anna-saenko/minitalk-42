/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:44:26 by asaenko           #+#    #+#             */
/*   Updated: 2024/02/26 14:47:05 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if ((dest == src) || (!dest && !src))
		return (dest);
	if (dest > src)
		while (count--)
			dest_cpy[count] = src_cpy[count];
	else
		while (count--)
			*dest_cpy++ = *src_cpy++;
	return (dest);
}
