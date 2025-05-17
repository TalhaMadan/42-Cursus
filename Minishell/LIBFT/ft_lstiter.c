/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:39 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 10:46:40 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list	*lst, void (*f)(void *))
{
	t_list	*iter;

	if (lst && f)
	{
		iter = lst;
		while (iter)
		{
			f(iter->content);
			iter = iter->next;
		}
	}
	return ;
}
