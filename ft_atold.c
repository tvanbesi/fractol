/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:33:27 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 21:14:49 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int
	get_int_count(const char *s)
{
	int	r;

	r = 0;
	while (ft_isdigit(*s++))
		r++;
	return (r);
}

long double
	ft_atold(const char *s)
{
	long double	r;
	int			int_count;
	int			i;
	int			sign;

	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	int_count = get_int_count(s);
	r = 0.0;
	i = 0;
	while (i++ < int_count)
		r += (*s++ - '0') * powl(10.0, int_count - i);
	if (*s == '.')
		s++;
	i = -1;
	while (*s)
		r += (*s++ - '0') * powl(10.0, i--);
	return (r * sign);
}
