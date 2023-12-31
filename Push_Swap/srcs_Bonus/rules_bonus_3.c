/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:38:48 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:39:55 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_list *list)
{
	int	temp;

	if (list->a_len != 0)
	{
		temp = list->a[list->a_len - 1];
		ft_up(list, 'a');
		list->a[0] = temp;
	}
}

void	rrb(t_list *list)
{
	int	temp;

	if (list->b_len != 0)
	{
		temp = list->b[list->b_len - 1];
		ft_up(list, 'b');
		list->b[0] = temp;
	}
}

void	rrr(t_list *list)
{
	int	temp;

	if (list->a_len != 0)
	{
		temp = list->a[list->a_len - 1];
		ft_up(list, 'a');
		list->a[0] = temp;
	}
	if (list->b_len != 0)
	{
		temp = list->b[list->b_len - 1];
		ft_up(list, 'b');
		list->b[0] = temp;
	}
}

void	ft_exit_e(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
