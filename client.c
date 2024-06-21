/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:55:33 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/21 18:23:23 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		i++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: %s [PID] [string]\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
		send_char(pid, *message++);
	send_char(pid, 0);
	return (0);
}
