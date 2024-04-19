/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:10:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/19 18:04:33 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_mandelbrot_pixel(int x, int y, int size_x, int size_y)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int		i;
	int		max_iter;

	c[0] = scale_x(x, size_x / 4, size_x / 2);
	c[1] = -1 * scale_x(y, size_y / 4, size_y / 2);
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
	return (get_color(i, max_iter));
}
