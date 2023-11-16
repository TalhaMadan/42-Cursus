/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:33:46 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:33:48 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*src1;
	size_t	i;

	i = 1;
	dest = (char *)dst;
	src1 = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (src1 < dest)
	{
		while (i <= len)
		{
			dest[len - i] = src1[len - i];
			i++;
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
