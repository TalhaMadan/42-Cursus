/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:07:26 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/01 22:07:29 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init_mlx(t_data *d)
{
	d->m.mlx = mlx_init();
	d->m.win = mlx_new_window(d->m.mlx, WIN_WIDTH, WIN_HEIGHT, "Talha");
	d->m.img = mlx_new_image(d->m.mlx, WIN_WIDTH, WIN_HEIGHT);
	d->m.addr = mlx_get_data_addr(d->m.img, &d->m.bits_per_pixel,
			&d->m.line_length, &d->m.endian);
}

void	my_mlx_pixel_put(t_m *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_win(t_m *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_putstr("Exited\n");
	exit(0);
	return (0);
}
