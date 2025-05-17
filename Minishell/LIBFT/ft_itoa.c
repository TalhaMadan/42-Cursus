/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:02 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 10:46:03 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	digitcount(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n / 10 >= 0)
	{
		n = n / 10;
		if (n == 0)
			break ;
		i++;
	}
	return (i);
}

static	char	*digitmalloc(long int n)
{
	int		i;
	char	*nb;

	i = digitcount(n);
	if (n < 0)
		i = i + 1;
	nb = malloc (i + 1);
	if (!nb)
		return (NULL);
	nb[i] = '\0';
	return (nb);
}

char	*ft_itoa(int n)
{
	char		*nb;
	int			i;
	long int	nm;

	nm = (long int)n;
	nb = digitmalloc(nm);
	if (!nb)
		return (NULL);
	if (nm < 0)
	{
		nm *= -1;
		nb[0] = '-';
	}
	i = digitcount(nm);
	if ((long int)n >= 0)
		i--;
	while (i >= 0)
	{
		nb[i] = nm % 10 + 48;
		nm = nm / 10;
		if (nm == 0)
			break ;
		i--;
	}
	return (nb);
}
