/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:09:20 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/14 18:09:09 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int
	isinset(float a, float b)
{
	float complex	c;
	float complex	z1;
	int				i;

	c = a + b * I;
	z1 = c;
	i = 0;
	while (i < 30)
	{
		c = cpowf(c, 2.0) + z1;
		if (isinf(creal(c)) || isinf(cimag(c)))
			return (0);
		i++;
	}
	return (1);
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

	black = create_trgb(0, 255, 255, 255);
	white = create_trgb(0, 0, 0, 0);
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			a = -2.0 + 2.5 * ((float)i / (float)x);
			b = -2.0 + 4.0 * ((float)j / (float)y);
			if (isinset(a, b))
				color_pixel(data, i, j, black);
			else
				color_pixel(data, i, j, white);
			j++;
		}
		i++;
	}
}
