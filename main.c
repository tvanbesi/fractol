/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:06:14 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 13:00:25 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	key_hook(int keycode, t_vars *vars)
{
	if (keycode == UP)
	{
		zoom(&vars->boundary);
		mandelbrot(&vars->img, vars->res, vars->boundary);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
	}
}

int
	main(int argc, char **argv)
{
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.res = (t_res){800, 800};
	vars.mlx_win = mlx_new_window(vars.mlx, vars.res.x, vars.res.y, "fractol");
	vars.img.img = mlx_new_image(vars.mlx, vars.res.x, vars.res.y);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	init_boundary(&vars.boundary, (t_complex){-0.7463, 0.1102}, (t_complex){5.0, 5.0}, 100);
	mandelbrot(&vars.img, vars.res, vars.boundary);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, 0, 0);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
