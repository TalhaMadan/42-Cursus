/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:36:59 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:41:33 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bmax(t_list *list)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < list->b_len)
	{
		if (list->b[index] < list->b[i])
			index = i;
		i++;
	}
	list->b_max_i = index;
}

void	bmin(t_list *list)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < list->b_len)
	{
		if (list->b[index] > list->b[i])
			index = i;
		i++;
	}
	list->b_min_i = index;
}

int	a_min(t_list *list)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < list->a_len)
	{
		if (list->a[index] > list->a[i])
			index = i;
		i++;
	}
	return (index);
}

void	take_cheapest(t_list *list)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < list->a_len)
	{
		if (list->steps[index] > list->steps[i])
			index = i;
		i++;
	}
	list->cheapest_index = index;
}

void	find_cheapest(t_list *list)
{
	bmax(list);
	bmin(list);
	calculate_steps(list);
	take_cheapest(list);
}
