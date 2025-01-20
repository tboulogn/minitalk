/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:57:00 by tboulogn          #+#    #+#             */
/*   Updated: 2025/01/20 17:29:34 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		res = nb * ft_recursive_power(nb, power -1);
		return (res);
	}
}

char	*letter_to_string(char const *message, char const letter)
{
	int		i;
	int		j;
	char	*tab;
	
	i = 0;
	j = 0;
	tab = malloc((ft_strlen(message) + 2) *sizeof(char));
	if (!tab)
		return (NULL);
	while (message[i])
		tab[j++] = message[i++];
	i = 0;
	tab[j++] = letter;
	tab[j] = 0;
	free((void *)message);
	return(tab);
}

void	signal_handler(int sigusrnum)
{
	static int	counter = 0;
	static int	result = 0;
	static int 	len = 0;
	static char	*final;

	if (!final)
		final = ft_strdup("");
	if (sigusrnum == SIGUSR1)
		result = result + 0;
	else if (sigusrnum == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - counter));
	counter++;
	if (counter == 8)
	{
		final = letter_to_string(final, result);
		if (result == '\0')
		{
			ft_printf("%s\n", final);
			free(final);
			final = NULL;
		}
		counter = 0;
		result = 0;
		len += 1;
	}
}

int	main(void)
{
	struct sigaction signal_received;

	ft_printf("Welcome to my server!\n");
	ft_printf("Server's PID is: %d\n", getpid());
	signal_received.sa_handler = signal_handler;
	signal_received.sa_flags = 0;
	sigemptyset(&signal_received.sa_mask);
	sigaddset(&signal_received.sa_mask, SIGUSR1);
	sigaddset(&signal_received.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		usleep(500);
}
