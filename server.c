/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:10:39 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/04 12:14:11 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_handler(int signum)
{
	static int	bits;
	static int	char_bit;

	if (signum == SIGUSR2)
	{
		char_bit |= (1 << bits);
	}
	bits++;
	if (bits == 8)
	{
		write(1, &char_bit, 1);
		bits = 0;
		char_bit = 0;
	}
}

void	set_signal_handlers(void)
{
	struct sigaction	signal;

	signal.sa_handler = bit_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = 0;
	if (sigaction(SIGUSR1, &signal, NULL) == -1 || \
		sigaction(SIGUSR2, &signal, NULL) == -1)
	{
		ft_printf("Error setting signal handlers\n");
		exit(1);
	}
}

int	main(void)
{
	ft_printf("The server is running>>>\n");
	ft_printf("Server PID:" GREEN " %d\n" RESET, getpid());
	set_signal_handlers();
	while (1)
	{
		pause();
	}
	return (0);
}
