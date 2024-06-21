/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:20:27 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/29 12:20:29 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		count += ft_putstr("(null)");
	else if (s)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
			count++;
		}
	}
	return (count);
}
