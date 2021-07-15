/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:05:43 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/15 10:07:01 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int
	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int
	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int
	get_b(int trgb)
{
	return (trgb & 0xFF);
}
