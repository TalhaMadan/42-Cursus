/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:33:52 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:33:55 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int src, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)dst;
	while (i < n)
	{
		str[i] = src;
		i++;
	}
	return (dst);
}
