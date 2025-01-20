/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:56:47 by tboulogn          #+#    #+#             */
/*   Updated: 2025/01/20 17:23:00 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *message)
{
	int	letter;
	int	i;
	
	letter = 0;
	while (message[letter])
	{
		i = 0;
		while (i < 8)
		{
			if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(500);
			i++;
		}
		letter++;
	}
	i = 0;
	while(i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(500);
		i++;
	}	
}

int	main(int ac, char **av)
{
	char	*message;
	int		server_id;

	if (ac == 3)
	{
		server_id = ft_atoi(av[1]);
		if(!server_id)
		{
			ft_printf("ERROR, wrong PID");
			return (0);
		}
		message = av[2];
		if(!message)
		{
			ft_printf("ERROR, nothing to send");
			return(0);
		}
		send_signals(server_id, message);
	}
	else
	{
		ft_printf("ERROR, not as argument as required.\n");
		ft_printf("Please enter arguments as follow: ./client <PID> <message>");
	}
	return (0);
}
