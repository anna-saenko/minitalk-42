/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:51:33 by asaenko           #+#    #+#             */
/*   Updated: 2024/07/07 20:52:10 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static volatile sig_atomic_t ack_received = 0;

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
	{
		ack_received = 1;
	}
	else if (sig == SIGUSR2)
	{
		write(1, "\nMessage acknowledged by server!\n", 33);
		exit(EXIT_SUCCESS);
	}
}

void	setup_ack_handler(int signum)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = handle_ack;
	sigemptyset(&sa.sa_mask);
	if (sigaction(signum, &sa, NULL) == -1)
	{
		ft_printf("sigaction");
		exit(EXIT_FAILURE);
	}
}

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		ack_received = 0;
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		while (!ack_received)
		{
			usleep(100);
		}
		bit++;
	}
}

void	send_string(const char *str, pid_t pid)
{
	while (*str)
	{
		send_char(*str, pid);
		str++;
	}
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	const char	*message;

	if (argc != 3)
	{
		write(1, "Usage: <server_pid> <message>\n", 30);
		exit(EXIT_FAILURE);
	}
	server_pid = (pid_t)atoi(argv[1]);
	message = argv[2];
	setup_ack_handler(SIGUSR1);
	setup_ack_handler(SIGUSR2);
	send_string(message, server_pid);
	while (1)
	{
		pause();
	}
	return 0;
}
