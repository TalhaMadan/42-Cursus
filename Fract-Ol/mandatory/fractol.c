/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:43:25 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/02 19:16:40 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	design_fracts(t_data *data)
{
	int	iter;
	int	pos_x;
	int	pos_y;

	pos_x = -1;
	pos_y = -1;
	while (++pos_y < WIN_HEIGHT)
	{
		pos_x = -1;
		while (++pos_x < WIN_WIDTH)
		{
			iter = data->fract_func(data, pos_x, pos_y);
			if (iter == data->max_iter)
				my_mlx_pixel_put(&(data->m), pos_x, pos_y, 0);
			else
				my_mlx_pixel_put(&(data->m), pos_x, pos_y, iter * data->color);
		}
	}
	mlx_clear_window(data->m.mlx, data->m.win);
	mlx_put_image_to_window(data->m.mlx, data->m.win, data->m.img, 0, 0);
	return (0);
}
