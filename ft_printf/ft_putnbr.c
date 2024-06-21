/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:20:43 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/29 12:20:46 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		count++;
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putchar(nb % 10 + '0');
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunsigned(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
