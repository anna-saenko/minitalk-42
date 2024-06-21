/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:20:55 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/29 12:21:41 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long x)
{
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (x >= 16)
	{
		count += ft_puthex(x / 16);
		count += ft_putchar(hex[x % 16]);
	}
	else
		count += ft_putchar(hex[x]);
	return (count);
}

int	ft_puthex_upper(unsigned long long x)
{
	int		count;
	char	*hex;

	hex = "0123456789ABCDEF";
	count = 0;
	if (x >= 16)
	{
		count += ft_puthex_upper(x / 16);
		count += ft_putchar(hex[x % 16]);
	}
	else
		count += ft_putchar(hex[x]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	ft_putstr("0x");
	count += 2;
	count += ft_puthex((unsigned long long)ptr);
	return (count);
}
