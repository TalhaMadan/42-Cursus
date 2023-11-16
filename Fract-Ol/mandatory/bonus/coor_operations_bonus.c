/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:04:01 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/02 19:39:52 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_point	move_base(t_point base, int pos_x, int pos_y, double zo_rate)
{
	t_point	moved_base;

	moved_base.coorx = (pos_x - base.posx) * zo_rate + base.coorx;
	moved_base.coory = (base.posy - pos_y) * zo_rate + base.coory;
	moved_base.posx = pos_x;
	moved_base.posy = pos_y;
	return (moved_base);
}

t_complex	calculate_coor(int pos_x, int pos_y, t_point base, double zo_rate)
{
	t_complex	comp;

	comp.real = (pos_x - base.posx) * zo_rate + base.coorx;
	comp.imag = (base.posy - pos_y) * zo_rate + base.coory;
	return (comp);
}
