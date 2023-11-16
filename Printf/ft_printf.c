/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:55:08 by tamadan           #+#    #+#             */
/*   Updated: 2023/03/20 19:49:41 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	control(char type, va_list list)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(list, int));
	else if (type == 's')
		len += ft_putstr(va_arg(list, char *));
	else if (type == 'd' || type == 'i')
		len += ft_putnbr(va_arg(list, int));
	else if (type == 'u')
		len += ft_putnbr(va_arg(list, unsigned));
	else if (type == 'p')
	{
		len += ft_address(va_arg(list, unsigned long int), 0);
	}
	else if (type == 'x' || type == 'X')
		len += ft_hexa(va_arg(list, unsigned), type);
	else if (type == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += write(1, &str[i++], 1);
		else
		{
			len += control(str[++i], list);
			i++;
		}
	}
	va_end(list);
	return (len);
}
