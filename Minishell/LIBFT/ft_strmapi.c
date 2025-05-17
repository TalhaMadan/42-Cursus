/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:49:49 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 10:49:50 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*returnarray;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	returnarray = (char *)malloc(sizeof(char) * (len + 1));
	if (!returnarray)
		return (NULL);
	i = -1;
	while (s[++i])
		returnarray[i] = f(i, s[i]);
	returnarray[i] = '\0';
	return (returnarray);
}
