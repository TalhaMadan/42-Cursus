/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:49:17 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 10:49:18 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	s1s2 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1s2)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		s1s2[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2))
		s1s2[i + j] = s2[j];
	s1s2[i + j] = '\0';
	if (s1)
		free((char *)s1);
	return (s1s2);
}
