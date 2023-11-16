/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:54:59 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/02 19:13:33 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_calo	fractal_type;

	fractal_type = check_args(ac, av);
	init_mlx(&data);
	init_data(&data, fractal_type, av);
	mlx_hook(data.m.win, 17, 0, close_win, &data.m);
	design_fracts(&data);
	mlx_key_hook(data.m.win, key_hook, &data);
	mlx_mouse_hook(data.m.win, mouse_hook, &data);
	mlx_loop(data.m.mlx);
}
