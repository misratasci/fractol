/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:10:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/19 16:10:52 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_x(int x, int size_x)
{
	double offset;
	double	scale;

	offset = (double)size_x / 2;
	scale = (double)size_x / 4;
	return ((x - offset) / scale);
}

double	scale_y(int y, int size_y)
{
	return (-scale_x(y, size_y));
}

int	get_mandelbrot_pixel(int x, int y, int size_x, int size_y)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int		i;
	int		max_iter;

	c[0] = scale_x(x, size_x);
	c[1] = scale_y(y, size_y);
	z[0] = 0;
	z[1] = 0;
	i = 0;
	max_iter = 50;
	//printf("c = %f + %fi\n", c[0], c[1]);
	while (z[0] * z[0] + z[1] * z[1] <= 4 && i < max_iter)
	{
		//printf("z = %f + %fi, x2 + y2 = %f, i = %d\n", z[0], z[1], z[0] * z[0] + z[1] * z[1], i);
		tmp = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = tmp;
		i++;
	}
	if (i == max_iter)
		return (0x00FF0000);
	return (0x00000000);
}