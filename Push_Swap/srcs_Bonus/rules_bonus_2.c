/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:38:45 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:39:58 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_list *list)
{
	if (list->b_len != 0)
	{
		ft_up(list, 'a');
		list->a[0] = list->b[0];
		list->a_len++;
		ft_down(list, 'b');
		list->b_len--;
	}
}

void	pb(t_list *list)
{
	if (list->a_len != 0)
	{
		ft_up(list, 'b');
		list->b[0] = list->a[0];
		list->b_len++;
		ft_down(list, 'a');
		list->a_len--;
	}
}

void	ra(t_list *list)
{
	int	temp;

	if (list->a_len != 0)
	{
		temp = list->a[0];
		ft_down(list, 'a');
		list->a[list->a_len - 1] = temp;
	}
}

void	rb(t_list *list)
{
	int	temp;

	if (list->b_len != 0)
	{
		temp = list->b[0];
		ft_down(list, 'b');
		list->b[list->b_len - 1] = temp;
	}
}

void	rr(t_list *list)
{
	int	temp;

	if (list->a_len != 0)
	{
		temp = list->a[0];
		ft_down(list, 'a');
		list->a[list->a_len - 1] = temp;
	}
	if (list->b_len != 0)
	{
		temp = list->b[0];
		ft_down(list, 'b');
		list->b[list->b_len - 1] = temp;
	}
}
