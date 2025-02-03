/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:54:26 by tboulogn          #+#    #+#             */
/*   Updated: 2025/02/03 10:49:14 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _GNU_SOURCE
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

char	*ft_strdup(char const *s);
int		ft_atoi(char *str);
int		ft_strlen(char const *str);

#endif