/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:06:14 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/18 16:48:58 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void
	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->res = (t_res){800, 800};
	vars->mlx_win = mlx_new_window(vars->mlx,
			vars->res.x, vars->res.y, "fractol");
	vars->img.img = mlx_new_image(vars->mlx, vars->res.x, vars->res.y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
}

static int
	sanity_check(const char *arg)
{
	if (*arg == '-')
		arg++;
	if (!ft_isdigit(*arg))
		return (0);
	while (ft_isdigit(*arg))
		arg++;
	if (*arg == '.')
		arg++;
	while (ft_isdigit(*arg))
		arg++;
	if (*arg)
		return (0);
	return (1);
}

static int
	parse_arg(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 1)
		return (-1);
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
	{
		fractal->type = MANDELBROT;
		return (0);
	}
	else if (!ft_strncmp(argv[1], "julia", 6))
		fractal->type = JULIA;
	else
		return (-1);
	if (fractal->type == JULIA && argc < 4)
		return (-1);
	if (!sanity_check(argv[2]) || !sanity_check(argv[3]))
		return (-1);
	if (fractal->type == JULIA)
		fractal->c = (t_complex){ft_atold(argv[2]), ft_atold(argv[3])};
	return (0);
}

int
	main(int argc, char **argv)
{
	t_vars		vars;

	if (parse_arg(argc, argv, &vars.fractal) == -1)
		exit_bad_arg();
	init_vars(&vars);
	init_boundary(&vars.boundary,
		(t_complex){0.0, 0.0}, (t_complex){5.0, 5.0}, 32);
	render(&vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_mouse_hook(vars.mlx_win, mouse_hook, &vars);
	mlx_hook(vars.mlx_win, 19, 1L << 17, refresh, &vars);
	mlx_hook(vars.mlx_win, 17, 0, close_hook, &vars);
	mlx_loop(vars.mlx);
}
