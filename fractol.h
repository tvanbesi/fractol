#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

# define LEFT			65361
# define UP				65362
# define RIGHT			65363
# define DOWN			65364
# define PLUS			65451
# define MINUS			65453
# define ESC			65307
# define SCROLL_UP		4
# define SCROLL_DOWN	5

# define WHITE			0x00FFFFFF
# define BLACK			0x00000000
# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define BLUE			0x000000FF

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_complex
{
	long double	r;
	long double	i;
}	t_complex;

typedef struct s_boundary
{
	t_complex	origin;
	t_complex	range;
	int			depth;
	t_complex	center;
}	t_boundary;

typedef struct s_res
{
	int	x;
	int	y;
}	t_res;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_res		res;
	t_data		img;
	t_boundary	boundary;

}	t_vars;

void		init_boundary(t_boundary *boundary,
				t_complex center, t_complex range, int depth);

void		color_pixel(t_data *data, int x, int y, int color);
void		color_by_depth(int depth, t_data *data, t_pos pos, int *gradient);
int			create_trgb(int t, int r, int g, int b);
int			*create_gradient(int color, int depth);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

t_complex	cadd(t_complex a, t_complex b);
t_complex	cpow2(t_complex c);

void		fractal(t_data *data, t_res res, t_boundary boundary);
int			mandelbrot(long double a, long double b, int depth);
int			julia(long double a, long double b, int depth, t_complex c);
void		zoom(t_boundary *boundary, long double n, t_vars *vars);
void		translate(t_boundary *boundary, int move, t_vars *vars);
void		change_iter_n(t_boundary *boundary, float p, t_vars *vars);

void		render(t_vars *vars);

void		exit_error(void);

#endif
