/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:55:54 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/01 21:55:57 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_COMPLEX_H
# define MY_COMPLEX_H

# include <math.h>

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

t_complex	complex_add(t_complex c1, t_complex c2);
t_complex	complex_subtract(t_complex c1, t_complex c2);
t_complex	complex_multiply(t_complex c1, t_complex c2);
t_complex	complex_squared(t_complex c);
double		complex_abs(t_complex c);
t_complex	complex_create(double real, double imaginary);

#endif