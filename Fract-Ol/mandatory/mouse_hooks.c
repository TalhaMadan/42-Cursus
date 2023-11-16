/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:45:40 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/02 20:11:44 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == SCROLL_UP)
		data->zoom -= 0.1;
	else if (keycode == SCROLL_DOWN)
		data->zoom += 0.1;
	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
	{
		data->zo_rate = pow(2, data->zoom);
	}
	design_fracts(data);
	return (0);
}
