/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:58:30 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 13:24:39 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	zoom(t_boundary *boundary, float n)
{
	boundary->range.r *= n;
	boundary->range.i *= n;
	boundary->origin.r = boundary->center.r - boundary->range.r / 2.0;
	boundary->origin.i = boundary->center.i - boundary->range.i / 2.0;
}
