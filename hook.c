/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:14:25 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/17 10:33:23 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	refresh(t_vars *vars)
{
	render(vars);
	return (0);
}

int
	close_hook(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int
	key_hook(int keycode, t_vars *vars)
{
	if (keycode == RIGHT)
		translate(&vars->boundary, RIGHT, vars);
	else if (keycode == LEFT)
		translate(&vars->boundary, LEFT, vars);
	else if (keycode == UP)
		translate(&vars->boundary, UP, vars);
	else if (keycode == DOWN)
		translate(&vars->boundary, DOWN, vars);
	else if (keycode == PLUS)
		change_iter_n(&vars->boundary, 2.0, vars);
	else if (keycode == MINUS)
		change_iter_n(&vars->boundary, 0.5, vars);
	else if (keycode == ESC)
		close_hook(vars);
	return (0);
}

int
	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		zoom(&vars->boundary, 0.5, vars);
	else if (button == SCROLL_DOWN)
		zoom(&vars->boundary, 2.0, vars);
	return (0);
}
