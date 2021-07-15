/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:06:14 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 10:21:28 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	key_hook(int keycode, t_vars *vars)
{
	printf("Key pressed: %d\n", keycode);
}

int
	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_vars	vars;
	int		x = 1800, y = 900;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x, y, "fractol");
	img.img = mlx_new_image(mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("rendering...\n");
	mandelbrot(&img, x, y);
	printf("done!\n");
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	vars.mlx = mlx;
	vars.win = mlx_win;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(mlx);
}
