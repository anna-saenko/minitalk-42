/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:53:14 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/05 12:53:20 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haystack;
	char	*needle;

	i = 0;
	haystack = (char *)s1;
	needle = (char *)s2;
	if (*needle == '\0')
		return (haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[j + i] && j + i < len)
		{
			if (needle[j + 1] == '\0')
			{
				return (haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
