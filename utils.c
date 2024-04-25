/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:03:14 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/25 13:05:18 by mitasci          ###   ########.fr       */
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

int	get_color(int i, int max_iter)
{
	if (i < max_iter / 5)
		return (0x00BAC1B8);
	if (i < 2 * max_iter / 5)
		return (0x0058A4B0);
	if (i < 3 * max_iter / 5)
		return (0x000C7C59);
	if (i < 4 * max_iter / 5)
		return (0x00D64933);
	return (0x002B303A);
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

int	count_in_str(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	valid_double(const char *s)
{
	int	i;
	i = 0;
	if (count_in_str(s, '.') > 1 || s[ft_strlen(s) - 1] == '.')
		return (0);
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
