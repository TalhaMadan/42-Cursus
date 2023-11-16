/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:34:34 by tamadan           #+#    #+#             */
/*   Updated: 2023/03/20 19:49:07 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (!str)
		str = "(null)";
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}

int	ft_putnbr(long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	else if (nbr < 10)
		len += ft_putchar(nbr + '0');
	return (len);
}

int	ft_hexa(unsigned long int nbr, char flag)
{
	const char	lowerbase[] = "0123456789abcdef";
	const char	upperbase[] = "0123456789ABCDEF";
	int			len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_hexa(nbr / 16, flag);
		len += ft_hexa(nbr % 16, flag);
	}
	else if (nbr < 16 && flag == 'x')
		len += write(1, &lowerbase[nbr % 16], 1);
	else if (nbr < 16 && flag == 'X')
		len += write(1, &upperbase[nbr % 16], 1);
	return (len);
}

int	ft_address(unsigned long long nbr, int instance)
{
	const char	*lowerbase = "0123456789abcdef";
	int			len;

	len = 0;
	if (instance == 0)
		len += ft_putstr("0x");
	if (nbr < 16)
		len += ft_putchar(lowerbase[nbr % 16]);
	else
	{
		len += ft_address(nbr / 16, instance + 1);
		len += ft_putchar(lowerbase[nbr % 16]);
	}
	return (len);
}
