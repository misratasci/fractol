/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:10:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/24 19:08:39 by mitasci          ###   ########.fr       */
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
	max_iter = 1000;
	//printf("c = %f + %fi\n", c[0], c[1]);
	while (z2[0] + z2[1] <= 4 && i < max_iter)
	{
		//printf("z = %f + %fi, x2 + y2 = %f, i = %d\n", z[0], z[1], z[0] * z[0] + z[1] * z[1], i);
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = z2[0] - z2[1] + c[0];
		z2[0] = z[0] * z[0];
		z2[1] = z[1] * z[1];
		i++;
	}
	return (get_color(i, max_iter));
}
/*
double	rev_scale_x(int c1, double scale, int offset)
{
	return (c1 * scale + offset);
}

double	rev_scale_y(int c2, double scale, int offset)
{
	return ((-1) * (c2 * scale + offset));
}

unsigned int	get_prev_pixel(double c1, double c2, t_app app)
{
	int	x;
	int	y;

	x = rev_scale_x(c1, app.scale, app.offset_x);
	y = rev_scale_y(c2, app.scale, app.offset_y);
	return (get_prev_color(app.img, x, y));
}

unsigned int rgb_to_hex(int r, int g, int b) {
    return (r << 16) | (g << 8) | b;
}

unsigned int	get_prev_color(t_data img, int x, int y)
{
	int	pix;
	int	color;

	pix = (x * (img.bits_per_pixel / 8)) + (y * img.line_length);
	color = rgb_to_hex(img.addr[pix], img.addr[pix + 1], img.addr[pix + 2]);
	return (color);
}

int	*get_prev_cx(t_app app)
{
	int	*prev_cx;

	prev_cx = (int *)malloc(sizeof(int) * )
}
*/