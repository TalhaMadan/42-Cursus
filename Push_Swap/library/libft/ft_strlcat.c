/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:34:51 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:34:53 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstsize;
	size_t	srcsize;
	size_t	i;

	if (!dst && !size)
		return (0);
	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize + 1 < size)
	{
		while (dstsize + i < size - 1 && src[i])
		{
			dst[dstsize + i] = src[i];
			i++;
		}
		dst[dstsize + i] = '\0';
	}
	if (dstsize + i >= size)
	{
		dstsize = size;
	}
	return (dstsize + srcsize);
}
