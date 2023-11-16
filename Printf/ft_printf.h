/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:05:12 by tamadan           #+#    #+#             */
/*   Updated: 2023/03/20 18:27:49 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long nbr);
int	ft_hexa(unsigned long int nbr, char flag);
int	ft_address(unsigned long long nbr, int instance);

int	control(char type, va_list list);
int	ft_printf(const char *str, ...);
#endif