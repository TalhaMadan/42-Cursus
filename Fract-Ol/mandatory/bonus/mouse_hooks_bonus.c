/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:07:37 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/02 19:30:58 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == SCROLL_UP)
		data->zoom -= 0.1;
	else if (keycode == SCROLL_DOWN)
		data->zoom += 0.1;
	else if (keycode == LEFT_CLICK)
		data->color = get_palette();
	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
	{
		data->zo_rate = pow(2, data->zoom);
		data->base = move_base(data->base, x, y, data->zo_rate);
	}
	design_fracts(data);
	return (0);
}
