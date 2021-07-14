#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <complex.h>

//REMOVE FOR DEFENCE
# include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	color_pixel(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

void	mandelbrot(t_data *data, int x, int y);

#endif
