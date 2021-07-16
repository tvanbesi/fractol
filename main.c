/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:06:14 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 12:22:35 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
}

int
	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == SCROLL_UP)
		zoom(&vars->boundary, 0.5, vars);
	else if (button == SCROLL_DOWN)
		zoom(&vars->boundary, 2.0, vars);
}

int
	main(int argc, char **argv)
{
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.res = (t_res){800, 800};
	vars.mlx_win = mlx_new_window(vars.mlx, vars.res.x, vars.res.y, "fractol");
	vars.img.img = mlx_new_image(vars.mlx, vars.res.x, vars.res.y);
	vars.img.addr = mlx_get_data_addr(vars.img.img,
			&vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	init_boundary(&vars.boundary,
		(t_complex){-0.745428, 0.113009}, (t_complex){5.0, 5.0}, 64);
	render(&vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_mouse_hook(vars.mlx_win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
