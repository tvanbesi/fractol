/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:18:50 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 19:25:01 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			tmp;

	tmp = n;
	if (n > ft_strlen(s1))
		n = ft_strlen(s1);
	if (n > ft_strlen(s2))
		n = ft_strlen(s2);
	if (n != tmp)
		n++;
	return (ft_memcmp(s1, s2, n));
}
