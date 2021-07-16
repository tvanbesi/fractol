/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:09:20 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 11:12:12 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	fractal(t_data *data, t_res res, t_boundary boundary)
{
	int			i;
	int			j;
	long double	a;
	long double	b;
	int			*gradient;

	gradient = create_gradient(RED, boundary.depth);
	if (!gradient)
		exit_error();
	i = -1;
	while (++i < res.x)
	{
		j = -1;
		a = boundary.origin.r + boundary.range.r
			* ((long double)i / (long double)res.x);
		while (++j < res.y)
		{
			b = boundary.origin.i + boundary.range.i
				* ((long double)j / (long double)res.y);
			color_by_depth(mandelbrot(a, b, boundary.depth),
				data, (t_pos){i, j}, gradient);
		}
	}
	free(gradient);
}
