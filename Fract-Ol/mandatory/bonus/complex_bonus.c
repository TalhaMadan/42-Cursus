/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:03:00 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/02 19:40:06 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_complex_bonus.h"

t_complex	complex_add(t_complex c1, t_complex c2)
{
	c1.real = c1.real + c2.real;
	c1.imag = c1.imag + c2.imag;
	return (c1);
}

t_complex	complex_subtract(t_complex c1, t_complex c2)
{
	c2.real *= -1;
	c2.imag *= -1;
	return (complex_add(c1, c2));
}

t_complex	complex_squared(t_complex c)
{
	return (complex_multiply(c, c));
}

double	complex_abs(t_complex c)
{
	return (sqrt(c.real * c.real + c.imag * c.imag));
}

t_complex	complex_create(double real, double imaginary)
{
	t_complex	c;

	c.real = real;
	c.imag = imaginary;
	return (c);
}
