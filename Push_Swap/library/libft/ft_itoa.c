/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:32:44 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:42:45 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int num)
{
	int	count;

	count = 0;
	if (num < 0 || num == 0)
		count++;
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*itoanext(char *number, int n, int len)
{
	if (number[len - 1] == '8')
	{
		len = len - 1;
	}
	while (n)
	{
		number[len-- - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;

	len = numlen(n);
	number = malloc(1 * len + 1);
	if (!number)
		return (NULL);
	if (n == 0)
		number[0] = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			number[len - 1] = '8';
			n /= 10;
		}
		number[0] = '-';
		n = -(n);
	}
	number[len] = '\0';
	itoanext(number, n, len);
	return (number);
}
