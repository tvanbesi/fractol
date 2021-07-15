#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>

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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_complex
{
	float	r;
	float	i;
}	t_complex;

void	color_pixel(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		*create_gradient(int color, int depth);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

t_complex	cadd(t_complex a, t_complex b);
t_complex	cpow2(t_complex c);

void	mandelbrot(t_data *data, int x, int y);

#endif
