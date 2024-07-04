/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:10:32 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/04 12:10:43 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char *str, int len)
{
	int		i;
	int		bit;
	char	ch;

	i = 0;
	while (i < len)
	{
		bit = 0;
		ch = str[i];
		while (bit < 8)
		{
			if ((ch >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit++;
			usleep(600);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	server_id;

	if (argc != 3)
	{
		ft_printf("Error! You should provice [Server PID] [Message]\n");
		return (0);
	}
	server_id = ft_atoi(argv[1]);
	send_message(server_id, argv[2], ft_strlen(argv[2]));
}
