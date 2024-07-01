/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:10:39 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/01 14:44:45 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
void handle_signal(int sig) {

}*/

int main()
{
	struct sigaction	signal;

    //signal.sa_handler = handle_signal;
    signal.sa_flags = 0;

	ft_printf("Server PID: %d\n", getpid());

	while (1)
	{
		pause();  // Wait for a signal to arrive
	}

	return 0;
}
