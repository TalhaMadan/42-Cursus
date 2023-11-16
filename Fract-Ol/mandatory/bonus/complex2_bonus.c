/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:03:30 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/01 22:03:49 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_complex_bonus.h"

t_complex	complex_multiply(t_complex c1, t_complex c2)
{
	t_complex	cc;

	cc.real = c1.real * c2.real - c1.imag * c2.imag;
	cc.imag = c1.real * c2.imag + c1.imag * c2.real;
	return (cc);
}
