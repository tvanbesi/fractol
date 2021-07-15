/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:11:44 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 10:45:21 by tvanbesi         ###   ########.fr       */
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

int
	*create_gradient(int color, int depth)
{
	int	*gradient;
	int	i;

	gradient = malloc(sizeof(int) * depth);
	if (!gradient)
		return (NULL);
	i = 0;
	while (i < depth)
	{
		gradient[i] = create_trgb(0,
		(get_r(color) >> 16) * ((float)i / (float)depth),
		(get_g(color) >> 8) * ((float)i / (float)depth),
		get_b(color) * ((float)i / (float)depth));
	//	gradient[i] = get_r(color) * ((float)i / (float)depth)
	//	+ get_g(color) * ((float)i / (float)depth)
	//	+ get_b(color) * ((float)i / (float)depth);
	//DONT DELETE : BEAUTIFUL BUG
	//	gradient[i] = create_trgb(0,
	//	get_r(color) * ((float)i / (float)depth),
	//	get_g(color) * ((float)i / (float)depth),
	//	get_b(color) * ((float)i / (float)depth));
		i++;
	}
	return (gradient);
}
