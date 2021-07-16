/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 10:36:31 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/16 20:37:01 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void
	exit_error(void)
{
	perror(strerror(errno));
	exit(-1);
}

void
	exit_bad_arg(void)
{
	printf("First argument must be \"mandelbrot\" or \"julia\"\n");
	printf("julia takes two additional arguments: two decimal number\n");
	printf("e.g. ./fractol julia 1.2 4.7\n");
	exit(-1);
}
