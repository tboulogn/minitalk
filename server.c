/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:57:00 by tboulogn          #+#    #+#             */
/*   Updated: 2025/02/03 10:06:19 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*letter_to_string(char const *message, char const letter)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc((ft_strlen(message) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (message[i])
		tab[j++] = message[i++];
	i = 0;
	tab[j++] = letter;
	tab[j] = 0;
	free((void *)message);
	return (tab);
}

void	signal_handler(int sigusrnum, siginfo_t *info, void *context)
{
	static int	counter = 0;
	static int	result = 0;
	static char	*final = NULL;

	(void)context;
	if (!final)
		final = ft_strdup("");
	if (sigusrnum == SIGUSR2)
		result += (1 << (7 - counter));
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
	}
	if (info && info->si_pid)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("Welcome to my server!\n");
	ft_printf("Server's PID is: %d\n", getpid());
	ft_printf("To send something do it as follow with client:\n");
	ft_printf("./client <PID> <message>\n");
	signal_received.sa_sigaction = signal_handler;
	signal_received.sa_flags = SA_SIGINFO;
	sigemptyset(&signal_received.sa_mask);
	sigaddset(&signal_received.sa_mask, SIGUSR1);
	sigaddset(&signal_received.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		pause();
}
