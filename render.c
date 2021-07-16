/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:11:45 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 12:12:22 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	render(t_vars *vars)
{
	fractal(&vars->img, vars->res, vars->boundary);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
}
