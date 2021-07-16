/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:58:08 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 19:16:18 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*cs1;
	unsigned const char	*cs2;

	cs1 = s1;
	cs2 = s2;
	while (n-- > 0)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		cs1++;
		cs2++;
	}
	return (0);
}
