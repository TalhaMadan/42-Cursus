/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsort_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:37:08 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:41:37 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fstart_rrr_utils(t_list *list, int take)
{
	if (take > 0 && take > list->b_len / 2)
	{
		rrr(list);
		take++;
		list->boole1 = 0;
	}
	else
		rra(list);
	list->cheapest_index = 0;
	return (take);
}

int	fstart_rrr(t_list *list, int take)
{
	if (list->cheapest_index == list->a_len - 1 && take == list->b_len - 1
		&& list->a_len > 1)
	{
		rrr(list);
		list->cheapest_index = 0;
		take = 0;
	}
	else if (list->cheapest_index == list->a_len - 1 && list->a_len > 1)
		take = fstart_rrr_utils(list, take);
	else if (take == list->b_len - 1 && list->b_len > 1)
	{
		if (list->cheapest_index != 0 && (list->a_len > 1
				&& list->cheapest_index > list->a_len / 2))
		{
			rrr(list);
			list->cheapest_index++;
			list->boole1 = 0;
		}
		else
			rrb(list);
		take = 0;
	}
	return (take);
}

int	ft_start_rr_utils(t_list *list, int take)
{
	if (take > 0 && list->cheapest_index != 0
		&& (list->cheapest_index <= list->a_len / 2 && take <= list->b_len / 2))
	{
		rr(list);
		list->boole2 = 0;
		list->cheapest_index--;
		take--;
	}
	else if (take > 0 && list->cheapest_index != 0
		&& (list->cheapest_index > list->a_len / 2 && take > list->b_len / 2))
	{
		rrr(list);
		list->cheapest_index++;
		take++;
		list->boole1 = 0;
	}
	return (take);
}

int	fstart_rr(t_list *list, int take)
{
	take = ft_start_rr_utils(list, take);
	if (list->cheapest_index != 0 && list->cheapest_index <= list->a_len / 2
		&& list->boole2)
	{
		ra(list);
		list->cheapest_index--;
	}
	else if (list->cheapest_index != 0 && (list->a_len > 1
			&& list->cheapest_index > list->a_len / 2) && list->boole1)
	{
		rra(list);
		list->cheapest_index++;
	}
	if (take > 0 && take <= list->b_len / 2 && list->boole2)
	{
		rb(list);
		take--;
	}
	else if (take > 0 && take > list->b_len / 2 && list->boole1)
	{
		rrb(list);
		take++;
	}
	return (take);
}
