/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:09:20 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 13:24:44 by tvanbesi         ###   ########.fr       */
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
		if (c.r * c.r + c.i * c.i > 4.0)
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
	{
		perror(strerror(errno));
		exit(-1);
	}
	i = 0;
	while (i < res.x)
	{
		j = 0;
		a = boundary.origin.r + boundary.range.r * ((float)i / (float)res.x);
		while (j < res.y)
		{
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
