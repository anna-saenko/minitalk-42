/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:14:31 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/29 12:15:15 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(const char **format, va_list args)
{
	int	count;

	count = 0;
	(*format)++;
	if (**format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (**format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (**format == 'd' || **format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (**format == 'x')
		count += ft_puthex(va_arg(args, unsigned int));
	else if (**format == 'X')
		count += ft_puthex_upper(va_arg(args, unsigned int));
	else if (**format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (**format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += ft_parse(&format, args);
		}
		else
		{
			ft_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
