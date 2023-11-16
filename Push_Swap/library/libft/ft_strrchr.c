/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:35:28 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:35:29 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ret = (char *)s;
		s++;
	}
	if (!(unsigned char)c && !*s)
		ret = ((char *)s);
	return (ret);
}
