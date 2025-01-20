/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:08:51 by tboulogn          #+#    #+#             */
/*   Updated: 2024/11/19 10:06:37 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *lenght)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*lenght) += 11;
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_len('-', lenght);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, lenght);
		ft_putnbr(nbr % 10, lenght);
	}
	else
		ft_putchar_len(nbr + '0', lenght);
}

void	ft_pointer(size_t pointer, int *lenght)
{
	char	string[25];
	char	*base_char;
	int		i;

	base_char = "0123456789abcdef";
	i = 0;
	if (pointer == 0)
	{
		ft_putstr_len("(nil)", lenght);
		return ;
	}
	write(1, "0x", 2);
	(*lenght) += 2;
	while (pointer != 0)
	{
		string[i] = base_char[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(string[i], lenght);
}

void	ft_unsigned_int(unsigned int ui, int *lenght)
{
	if (ui >= 10)
		ft_unsigned_int(ui / 10, lenght);
	ft_putchar_len(ui % 10 + '0', lenght);
}

void	ft_hexdec(unsigned int ui, int *lenght, char xtype)
{
	char	string[25];
	char	*base_char;
	int		i;

	if (xtype == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	i = 0;
	if (ui == 0)
	{
		ft_putchar_len('0', lenght);
		return ;
	}
	while (ui != 0)
	{
		string[i] = base_char[ui % 16];
		ui = ui / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(string[i], lenght);
}
