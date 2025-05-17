/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:48:33 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 10:48:34 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*coppiedarray;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	coppiedarray = malloc(len * sizeof(char));
	if (!coppiedarray)
		return (NULL);
	coppiedarray = (char *)ft_memcpy(coppiedarray, s1, len);
	return (coppiedarray);
}
