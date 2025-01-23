/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:56:47 by tboulogn          #+#    #+#             */
/*   Updated: 2025/01/23 16:14:10 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_confirmation_received;

void	confirmation_handler(int sig)
{
	(void)sig;
	g_confirmation_received = 1;
}

void	send_bits(int pid, int bit)
{
	g_confirmation_received = 0;
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (!g_confirmation_received)
		pause();
	usleep(100);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bits(pid, (c >> i) & 1);
		i--;
	}
}

void	send_signals(int pid, char *message)
{
	int	letter;
	int	i;

	letter = 0;
	ft_printf("Waiting for server confirmation...\n");
	ft_printf("If it takes to much time check PID\n");
	while (message[letter])
	{
		send_char(pid, message[letter]);
		letter++;
	}
	i = 0;
	while (i < 8)
	{
		send_bits(pid, 0);
		i++;
	}
	while (!g_confirmation_received)
		pause();
	ft_printf("Message delivered successfully!\n");
}

int	main(int ac, char **av)
{
	char	*message;
	int		server_id;

	signal(SIGUSR2, confirmation_handler);
	if (ac == 3)
	{
		server_id = ft_atoi(av[1]);
		if (server_id <= 0)
		{
			ft_printf("ERROR, wrong PID");
			return (0);
		}
		ft_printf("If it doesn't close or takes time, check PID\n");
		message = av[2];
		send_signals(server_id, message);
	}
	else
	{
		ft_printf("Error, please enter arguments as follow:\n");
		ft_printf("./client <PID> <message>\n");
	}
	return (0);
}
