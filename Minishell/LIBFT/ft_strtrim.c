/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:50:12 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 10:50:13 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*cuttedstring;
	int		i;
	int		endofs;

	if (s != NULL)
	{
		i = 0;
		while (s[i] && ft_strchr(set, s[i]))
			i++;
		endofs = ft_strlen(s) - 1;
		while (endofs > i && ft_strchr(set, s[endofs]))
			endofs--;
		cuttedstring = ft_substr(s, i, endofs - i + 1);
		return (cuttedstring);
	}
	return (NULL);
}
