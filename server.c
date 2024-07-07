/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:55:39 by asaenko           #+#    #+#             */
/*   Updated: 2024/07/07 20:40:40 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static data_t	data = {0};


void	set_sig_info(int sig, siginfo_t *info)
{
	if (info && data.client_pid == 0)
	{
		data.client_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
	{
		data.current_char |= (1 << data.bit_count);
	}
	else if (sig == SIGUSR2)
	{
		data.current_char &= ~(1 << data.bit_count);
	}
	data.bit_count++;
}


void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	set_sig_info(sig, info);
	if (data.bit_count == 8)
	{
		if (data.current_char == '\0') {
			write(1, "\nMessage received!\n", 19);
			kill(data.client_pid, SIGUSR2);
			data.client_pid = 0;
		}
		else
		{
			write(1, &data.current_char, 1);
		}
		data.bit_count = 0;
		data.current_char = 0;
	}
	if (data.client_pid != 0)
		kill(data.client_pid, SIGUSR1);
}

void	setup_signal_handler(int signum)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	if (sigaction(signum, &sa, NULL) == -1)
	{
		ft_printf("sigaction");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	setup_signal_handler(SIGUSR1);
	setup_signal_handler(SIGUSR2);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return 0;
}
