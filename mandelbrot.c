/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:10:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/25 13:46:24 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_mandelbrot_pixel(int x, int y, t_app app)
{
	double	c[2];
	double	z[2];
	double	z2[2];
	int		i;
	int		max_iter;

	c[0] = scale_x(x, app.scale, app.offset_x);
	c[1] = scale_y(y, app.scale, app.offset_y);
	z[0] = 0;
	z[1] = 0;
	z2[0] = 0;
	z2[1] = 0;
	i = 0;
	max_iter = 100;
	while (z2[0] + z2[1] <= 4 && i < max_iter)
	{
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = z2[0] - z2[1] + c[0];
		z2[0] = z[0] * z[0];
		z2[1] = z[1] * z[1];
		i++;
	}
	return (get_color(i, max_iter));
}
