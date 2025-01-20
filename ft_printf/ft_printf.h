/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:08:23 by tboulogn          #+#    #+#             */
/*   Updated: 2024/11/19 09:41:09 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

void	ft_check(char c, va_list *args, int *lenght);
void	ft_putstr_len(char *args, int *lenght);
void	ft_putchar_len(char c, int *lenght);
void	ft_putnbr(int nbr, int *lenght);
void	ft_pointer(size_t pointer, int *lenght);
void	ft_unsigned_int(unsigned int ui, int *lenght);
void	ft_hexdec(unsigned int ui, int *lenght, char xtype);

#endif