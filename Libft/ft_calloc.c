/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:45:58 by tamadan           #+#    #+#             */
/*   Updated: 2023/01/18 20:38:15 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (0);
	p = malloc (count * size);
	if (!p)
		return (NULL);
	ft_bzero (p, count * size);
	return (p);
}
