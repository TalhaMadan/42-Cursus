/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_calculating.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:43:18 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/02 19:01:01 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_iter_mandelbrot(t_data *d, int pos_x, int pos_y)
{
	t_complex	constant;
	t_complex	current_pos;
	int			iteration;

	constant = calculate_coor(pos_x, pos_y, d->base, d->zo_rate);
	current_pos = constant;
	iteration = 0;
	while (complex_abs(current_pos) <= 2 && iteration < d->max_iter)
	{
		current_pos = calculate_new_position(current_pos, constant);
		iteration++;
	}
	return (iteration);
}

int	get_iter_julia(t_data *d, int pos_x, int pos_y)
{
	t_complex	current_pos;
	int			iteration;

	current_pos = calculate_coor(pos_x, pos_y, d->base, d->zo_rate);
	iteration = 0;
	while (complex_abs(current_pos) <= 2 && iteration < d->max_iter)
	{
		current_pos = calculate_new_position(current_pos, d->julia_constant);
		iteration++;
	}
	return (iteration);
}

t_complex	calculate_new_position(t_complex current, t_complex c)
{
	current = complex_squared(current);
	return (complex_add(current, c));
}
