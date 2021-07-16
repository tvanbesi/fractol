/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:09:20 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 20:45:22 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	fractal(t_vars *vars)
{
	int			i;
	int			j;
	long double	a;
	long double	b;
	int			*gradient;

	gradient = create_gradient(RED, vars->boundary.depth);
	if (!gradient)
		exit_error();
	i = -1;
	while (++i < vars->res.x)
	{
		j = -1;
		a = vars->boundary.origin.r + vars->boundary.range.r
			* ((long double)i / (long double)vars->res.x);
		while (++j < vars->res.y)
		{
			b = vars->boundary.origin.i + vars->boundary.range.i
				* ((long double)j / (long double)vars->res.y);
			if (vars->fractal.type == MANDELBROT)
			{
				color_by_depth(mandelbrot(a, b, vars->boundary.depth),
						&vars->img, (t_pos){i, j}, gradient);
			}
			else if (vars->fractal.type == JULIA)
			{
				color_by_depth(julia(a, b, vars->boundary.depth,
						vars->fractal.c), &vars->img, (t_pos){i, j}, gradient);
			}
		}
	}
	free(gradient);
}
