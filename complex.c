/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 08:55:34 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 09:13:59 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex
	cadd(t_complex a, t_complex b)
{
	t_complex	sum;

	sum.r = a.r + b.r;
	sum.i = a.i + b.i;
	return (sum);
}

t_complex
	cpow2(t_complex c)
{
	t_complex	prod;

	prod.r = c.r * c.r - c.i * c.i;
	prod.i = 2 * c.r * c.i;
	return (prod);
}
