/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:11:40 by asaenko           #+#    #+#             */
/*   Updated: 2024/07/07 20:32:43 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct {
	volatile sig_atomic_t	client_pid;
	int						bit_count;
	char					current_char;
} data_t;


#endif
