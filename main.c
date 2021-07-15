/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:06:14 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 11:54:28 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	key_hook(int keycode, t_vars *vars)
{
	printf("Key pressed: %d\n", keycode);
}

static void
	init_boundary(t_boundary *boundary, t_complex center, t_complex range)
{
	boundary->origin.r = center.r - range.r / 2.0;
	boundary->origin.i = center.i - range.i / 2.0;
	boundary->range = range;
}

int
	main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_vars		vars;
	int			x = 1800, y = 900;
	t_boundary	boundary;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x, y, "fractol");
	img.img = mlx_new_image(mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	init_boundary(&boundary, (t_complex){-0.75, 0}, (t_complex){2.5, 2.0});
	mandelbrot(&img, x, y, boundary);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	vars.mlx = mlx;
	vars.win = mlx_win;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(mlx);
}
