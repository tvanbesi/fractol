/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:06:35 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 11:09:41 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	julia(long double a, long double b, int depth, t_complex c)
{
	t_complex	z;
	int			i;

	z.r = a;
	z.i = b;
	i = 0;
	while (i < depth)
	{
		z = cadd(cpow2(z), c);
		if (z.r * z.r + z.i * z.i > 4.0)
			return (i);
		i++;
	}
	return (-1);
}
