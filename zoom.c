/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:58:30 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 12:57:09 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	zoom(t_boundary *boundary)
{
	boundary->range.r /= 2.0;
	boundary->range.i /= 2.0;
	boundary->origin.r = boundary->center.r - boundary->range.r / 2.0;
	boundary->origin.i = boundary->center.i - boundary->range.i / 2.0;
}
