/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:47:12 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/05 12:47:16 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	unsigned char	*ptr_cpy;
	unsigned char	c;
	size_t			i;

	ptr_cpy = (unsigned char *)ptr;
	c = (unsigned char)ch;
	i = 0;
	while (i < count)
	{
		if (ptr_cpy[i] == c)
		{
			return (ptr_cpy + i);
		}
		i++;
	}
	return (NULL);
}
