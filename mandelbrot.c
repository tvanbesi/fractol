/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:09:20 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 10:32:30 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int
	get_depth(long double a, long double b, int depth)
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
	int			i;
	int			j;
	long double	a;
	long double	b;
	int			depth;
	int			*gradient;

	gradient = create_gradient(RED, boundary.depth);
	if (!gradient)
	{
		perror(strerror(errno));
		exit(-1);
	}
	i = 0;
	while (i < res.x)
	{
		j = 0;
		a = boundary.origin.r + boundary.range.r * ((long double)i / (long double)res.x);
		while (j < res.y)
		{
			b = boundary.origin.i + boundary.range.i * ((long double)j / (long double)res.y);
			color_by_depth(get_depth(a, b, boundary.depth), data, (t_pos){i, j}, gradient);
//			depth = isinset(a, b, boundary.depth);
//			if (depth == -1)
//				color_pixel(data, i, j, BLACK);
//			else
//				color_pixel(data, i, j, gradient[depth]);
			j++;
		}
		i++;
	}
	free(gradient);
}
