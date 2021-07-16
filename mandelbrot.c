/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:03:25 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 12:18:35 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	mandelbrot(long double a, long double b, int depth)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z.r = a;
	z.i = b;
	c = z;
	i = 0;
	while (i < depth)
	{
		z = cadd(cpow2(z), c);
		if (z.r * z.r + z.i * z.i > 4.0)
			return (i);
		i++;
	}
	return (-1);
}
