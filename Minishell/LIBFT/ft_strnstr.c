/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:49:59 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 10:50:00 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (src[0] == '\0')
		return ((char *)dest);
	else
	{
		i = -1;
		while (++i < size && dest[i])
		{
			j = 0;
			while (dest[i + j] == src[j] && (i + j) < size)
			{
				if (src[j + 1] == '\0')
					return ((char *)dest + i);
				j++;
			}
		}
	}
	return (NULL);
}
