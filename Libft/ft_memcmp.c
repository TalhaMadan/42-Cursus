/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:46:21 by tamadan           #+#    #+#             */
/*   Updated: 2023/01/18 20:38:42 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n > i)
	{
		if (*(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		{
			i++;
		}
		else
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	}
	return (0);
}
