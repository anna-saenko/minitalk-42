/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:12:58 by asaenko           #+#    #+#             */
/*   Updated: 2024/02/20 14:04:46 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	size_t			i;
	unsigned char	*dest_cpy;

	i = 0;
	dest_cpy = (unsigned char *)dest;
	while (i < count)
	{
		dest_cpy[i] = (unsigned char)ch;
		i++;
	}
	return (dest);
}
