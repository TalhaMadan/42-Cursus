/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:48:01 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/02 18:58:51 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_parameters(void)
{
	ft_putstr("!!We don't have any fractal like this!!\n\
The fractals you can choose in here:\n\
-Mandelbrot\n-Julia\n\
Note: You must enter the two number for Julia!!\n");
}

void	show_params_and_exit_fail(void)
{
	show_parameters();
	exit(EXIT_FAILURE);
}

short	check_dstr_is_float(char **dstr, int len)
{
	int	ln;

	ln = 0;
	while (ln < len && dstr[ln])
	{
		if (ft_strlen(dstr[ln]) < 1)
			return (0);
		if (ft_count_c_in_str(dstr[ln], '.') > 1 || !is_str_digit(dstr[ln]))
			return (0);
		if (dstr[ln][0] == '.' || dstr[ln][ft_strlen(dstr[ln]) - 1] == '.')
			return (0);
		ln++;
	}
	return (1);
}

t_calo	check_args(int ac, char **av)
{
	t_calo	fractal_type;

	fractal_type = FRACT_NONE;
	if (ac < 2)
		show_params_and_exit_fail();
	if (ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1]) + 1) == 0)
		fractal_type = FRACT_MANDEL;
	if (fractal_type == FRACT_MANDEL && ac != 2)
		show_params_and_exit_fail();
	if (ft_strncmp(av[1], "Julia", ft_strlen(av[1]) + 1) == 0)
		fractal_type = FRACT_JULIA;
	if (fractal_type == FRACT_NONE)
		show_params_and_exit_fail();
	if (fractal_type == FRACT_JULIA)
	{
		if (ac != 4)
			show_params_and_exit_fail();
		if (check_dstr_is_float(&av[2], 2) == 0)
			show_params_and_exit_fail();
	}
	return (fractal_type);
}

void	init_data(t_data *data, t_calo fractal_type, char **av)
{
	data->zoom = ZOOM;
	data->zo_rate = pow(2, data->zoom);
	data->max_iter = MAX_ITER;
	data->color = 616761;
	data->base.coorx = 0;
	data->base.coory = 0;
	data->base.posx = WIN_WIDTH / 2;
	data->base.posy = WIN_HEIGHT / 2;
	if (fractal_type == FRACT_MANDEL)
		data->fract_func = get_iter_mandelbrot;
	else if (fractal_type == FRACT_JULIA)
	{
		data->fract_func = get_iter_julia;
		data->julia_constant.real = ft_atof(av[2]);
		data->julia_constant.imag = ft_atof(av[3]);
	}
}
