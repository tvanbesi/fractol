/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:09:20 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 10:24:54 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
**
**	Return -1 if in set
**	return depth otherwise
**
**/

static int
	isinset(float a, float b, int depth)
{
	t_complex	c;
	t_complex	z1;
	int			i;

	c.r = a;
	c.i = b;
	z1 = c;
	i = 0;
	while (i < depth)
	{
		c = cadd(cpow2(c), z1);
		if (isinf(c.r) || isinf(c.i))
			return (i);
		i++;
	}
	return (-1);
}

void
	mandelbrot(t_data *data, int x, int y)
{
	int		i;
	int		j;
	int		black;
	int		white;
	float	a;
	float	b;
	int		depth;
	int		gradient_depth;
	int		*gradient;

	black = create_trgb(0, 0, 0, 0);
	white = create_trgb(0, 255, 255, 255);
	gradient_depth = 75;
	gradient = create_gradient(white, gradient_depth);
	if (!gradient)
		return ; //free as well
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			a = -2.0 + 2.5 * ((float)i / (float)x);
			b = -1.0 + 2.0 * ((float)j / (float)y);
			depth = isinset(a, b, gradient_depth);
			if (depth == -1)
				color_pixel(data, i, j, black);
			else
				//color_pixel(data, i, j, white);
				color_pixel(data, i, j, gradient[depth]);
			j++;
		}
		i++;
	}
	free(gradient);
}
