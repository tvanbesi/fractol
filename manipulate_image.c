/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:58:30 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 12:21:05 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	zoom(t_boundary *boundary, long double n, t_vars *vars)
{
	boundary->range.r *= n;
	boundary->range.i *= n;
	boundary->origin.r = boundary->center.r - boundary->range.r / 2.0;
	boundary->origin.i = boundary->center.i - boundary->range.i / 2.0;
	render(vars);
}

void
	change_iter_n(t_boundary *boundary, float p, t_vars *vars)
{
	boundary->depth *= p;
	if (boundary->depth == 0)
		boundary->depth = 1;
	render(vars);
}

void
	translate(t_boundary *boundary, int move, t_vars *vars)
{
	if (move == RIGHT)
		boundary->center.r += boundary->range.r / 10.0;
	else if (move == LEFT)
		boundary->center.r -= boundary->range.r / 10.0;
	else if (move == UP)
		boundary->center.i -= boundary->range.i / 10.0;
	else if (move == DOWN)
		boundary->center.i += boundary->range.i / 10.0;
	boundary->origin.r = boundary->center.r - boundary->range.r / 2.0;
	boundary->origin.i = boundary->center.i - boundary->range.i / 2.0;
	render(vars);
}
