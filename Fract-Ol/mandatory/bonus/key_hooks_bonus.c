/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:05:54 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/02 19:10:49 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_win(&(data->m));
	else if (keycode == KEY_UP || keycode == KEY_W)
		data->base.coory += data->zo_rate * MOVE_STEP;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		data->base.coory -= data->zo_rate * MOVE_STEP;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		data->base.coorx -= data->zo_rate * MOVE_STEP;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		data->base.coorx += data->zo_rate * MOVE_STEP;
	design_fracts(data);
	return (0);
}
