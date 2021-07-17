/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:09:20 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/17 09:26:42 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void
	fractal_by_type(t_vars *vars, t_pos pos, int *gradient, t_complex c)
{
	if (vars->fractal.type == MANDELBROT)
	{
		color_by_depth(mandelbrot(c.r, c.i, vars->boundary.depth),
			&vars->img, pos, gradient);
	}
	else if (vars->fractal.type == JULIA)
	{
		color_by_depth(julia(c.r, c.i, vars->boundary.depth,
				vars->fractal.c), &vars->img, pos, gradient);
	}
}

void
	fractal(t_vars *vars)
{
	int			i;
	int			j;
	t_complex	c;
	int			*gradient;

	gradient = create_gradient(RED, vars->boundary.depth);
	if (!gradient)
		exit_error();
	i = -1;
	while (++i < vars->res.x)
	{
		j = -1;
		c.r = vars->boundary.origin.r + vars->boundary.range.r
			* ((long double)i / (long double)vars->res.x);
		while (++j < vars->res.y)
		{
			c.i = vars->boundary.origin.i + vars->boundary.range.i
				* ((long double)j / (long double)vars->res.y);
			fractal_by_type(vars, (t_pos){i, j}, gradient, c);
		}
	}
	free(gradient);
}
