/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:10:39 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/02 13:14:38 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void bit_handler(int signum)
{
    if (signum == SIGUSR1)
    {
        // Handle SIGUSR1 (bit 0)
        printf("Received SIGUSR1 (bit 0)\n");
    }
    else if (signum == SIGUSR2)
    {
        // Handle SIGUSR2 (bit 1)
        printf("Received SIGUSR2 (bit 1)\n");
    }
}

int main()
{
	//struct sigaction	signal;

    //signal.sa_handler = handle_signal;
   // signal.sa_flags = 0;
	ft_printf("The server is running>>>");
	ft_printf("Server PID: %d\n", getpid());

	while (1)
	{
		signal(SIGUSR2, bit_handler);
        signal(SIGUSR1, bit_handler);
		pause();  // Wait for a signal to arrive
	}

	return 0;
}
