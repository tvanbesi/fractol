/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:09:20 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 12:08:56 by tvanbesi         ###   ########.fr       */
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
	mandelbrot(t_data *data, t_res res, t_boundary boundary)
{
	int		i;
	int		j;
	int		black;
	int		white;
	float	a;
	float	b;
	int		depth;
	int		*gradient;

	black = create_trgb(0, 0, 0, 0);
	white = create_trgb(0, 255, 255, 255);
	gradient = create_gradient(white, boundary.depth);
	if (!gradient)
		return ; //malloc failed
	i = 0;
	while (i < res.x)
	{
		j = 0;
		while (j < res.y)
		{
			a = boundary.origin.r + boundary.range.r * ((float)i / (float)res.x);
			b = boundary.origin.i + boundary.range.i * ((float)j / (float)res.y);
			depth = isinset(a, b, boundary.depth);
			if (depth == -1)
				color_pixel(data, i, j, black);
			else
				color_pixel(data, i, j, gradient[depth]);
			j++;
		}
		i++;
	}
	free(gradient);
}
