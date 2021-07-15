/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:05:51 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 12:57:22 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	init_boundary(t_boundary *boundary, t_complex center, t_complex range, int depth)
{
	boundary->center = center;
	boundary->origin.r = center.r - range.r / 2.0;
	boundary->origin.i = center.i - range.i / 2.0;
	boundary->range = range;
	boundary->depth = depth;
}
