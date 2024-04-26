/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:03:14 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/26 17:21:18 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_x(int x, double scale, int offset)
{
	return ((x - offset) / scale);
}

double	scale_y(int y, double scale, int offset)
{
	return ((offset - y) / scale);
}

int	get_color(int i)
{
	return (i * 0x00030609);
}

void	fill_image(int size_x, t_data *img, t_app app)
{
	int	x;
	int	y;
	int	pix;
	int	color;

	x = 0;
	while (x < size_x)
	{
		y = 0;
		while (y < size_x)
		{
			pix = (x * (img->bits_per_pixel / 8)) + (y * img->line_length);
			if (app.fractal == 'm')
				color = get_mandelbrot_pixel(x, y, app);
			else
				color = get_julia_pixel(x, y, app);
			img->addr[pix] = color & 0xFF;
			img->addr[pix + 1] = (color >> 8) & 0xFF;
			img->addr[pix + 2] = (color >> 16) & 0xFF;
			y++;
		}
		x++;
	}
}

void	draw(t_app *app)
{
	fill_image(app->win_size, &(app->img), *app);
	mlx_put_image_to_window(app->mlx, app->mlx_win, app->img.img, 0, 0);
}
