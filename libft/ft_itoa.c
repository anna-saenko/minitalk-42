/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:57:11 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/05 12:58:29 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	find_abs_val(long long n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}

static int	count_digits(long long n)
{
	int	count;

	count = 1;
	n /= 10;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static int	check_negative(int n)
{
	if (n < 0)
	{
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	int			is_negative;
	long long	abs_n;
	int			num_digits;
	char		*result;
	int			index;

	is_negative = check_negative(n);
	abs_n = find_abs_val((long long)n);
	num_digits = count_digits(abs_n);
	result = (char *)malloc((num_digits + is_negative + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (is_negative)
		result[0] = '-';
	index = num_digits + is_negative - 1;
	result[index + 1] = '\0';
	while (index >= is_negative)
	{
		result[index] = (abs_n % 10) + '0';
		abs_n /= 10;
		index--;
	}
	return (result);
}
