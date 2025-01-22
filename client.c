/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:56:47 by tboulogn          #+#    #+#             */
/*   Updated: 2025/01/22 19:31:10 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	confirmation_received = 0;

void	confirmation_handler(int sig)
{
	(void)sig;
	confirmation_received = 1;
}

void send_signals(int pid, char *message)
{
    int letter = 0;
    int i;

    while (message[letter])
    {
        i = 0;
        while (i < 8)
        {
            confirmation_received = 0;
            if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            while (!confirmation_received) // Attendre la confirmation
                ;
            i++;
        }
        letter++;
    }
    i = 0;
    while (i < 8) // Envoyer 8 signaux SIGUSR1 pour indiquer la fin du message
    {
        confirmation_received = 0;
        kill(pid, SIGUSR1);
        while (!confirmation_received)
            ;
        i++;
    }
}

int	main(int ac, char **av)
{
	char	*message;
	int		server_id;

	signal(SIGUSR2, confirmation_handler);
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
