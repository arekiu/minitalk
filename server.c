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
    static int  bits;
    static int  char_bit;

    if (signum == SIGUSR2)
    {
        char_bit |= (1 << bits);
    }
    bits++;
    if (bits == 8)
    {
        ft_printf("%c", char_bit);
        bits = 0;
        char_bit = 0;
    }
}

int main()
{
	ft_printf("The server is running>>>");
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bit_handler);
        signal(SIGUSR1, bit_handler);
		pause();
	}
	return 0;
}
