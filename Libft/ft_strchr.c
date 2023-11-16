/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:46:44 by tamadan           #+#    #+#             */
/*   Updated: 2023/01/18 20:50:20 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int i)
{
	while (*str != '\0' && (char) i != *str)
			str++;
	if (*str == (char)i)
		return ((char *)str);
		str++;
	return (NULL);
}
