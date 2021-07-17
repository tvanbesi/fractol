/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:11:44 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/17 10:30:24 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	color_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int
	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void
	color_by_depth(int depth, t_data *data, t_pos pos, int *gradient)
{
	if (depth == -1)
		color_pixel(data, pos.x, pos.y, BLACK);
	else
		color_pixel(data, pos.x, pos.y, gradient[depth]);
}

int
	*create_gradient(int color, int depth)
{
	int	*gradient;
	int	i;
	int	comp;

	gradient = malloc(sizeof(int) * depth);
	if (!gradient)
		return (NULL);
	comp = ~color;
	i = 0;
	while (i < depth)
	{
		gradient[i] = create_trgb(0,
				(get_r(color) >> 16) * (1.0 - (float)i / (float)depth)
				+ (get_r(comp) >> 16) * ((float)i / (float)depth),
				(get_g(color) >> 8) * (1.0 - (float)i / (float)depth)
				+ (get_g(comp) >> 8) * ((float)i / (float)depth),
				get_b(color) * (1.0 - (float)i / (float)depth)
				+ get_b(comp) * ((float)i / (float)depth));
		i++;
	}
	return (gradient);
}
