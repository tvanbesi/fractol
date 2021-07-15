/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:06:14 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 12:13:48 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int
	main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_res		res;
	t_boundary	boundary;

	mlx = mlx_init();
	res = (t_res){1800, 900};
	mlx_win = mlx_new_window(mlx, res.x, res.y, "fractol");
	img.img = mlx_new_image(mlx, res.x, res.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	init_boundary(&boundary, (t_complex){-0.7463, 0.1102}, (t_complex){5.0, 5.0}, 100);
	mandelbrot(&img, res, boundary);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
