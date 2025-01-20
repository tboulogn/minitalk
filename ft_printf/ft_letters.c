/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:39:35 by tboulogn          #+#    #+#             */
/*   Updated: 2024/11/19 09:41:16 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, int *lenght)
{
	write(1, &c, 1);
	(*lenght)++;
}

void	ft_putstr_len(char *args, int *lenght)
{
	int	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*lenght) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putchar_len(args[i], lenght);
		i++;
	}
}
