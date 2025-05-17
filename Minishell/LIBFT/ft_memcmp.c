/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:47:16 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 10:47:17 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char *) s1;
	d2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((n - 1) > 0)
	{
		if (*d1 == *d2)
		{
			d1++;
			d2++;
		}
		else
			break ;
		n--;
	}
	return (*d1 - *d2);
}
