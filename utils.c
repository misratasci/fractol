/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:03:14 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/25 18:01:34 by mitasci          ###   ########.fr       */
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
	if (i % 10 == 0)
		return (0x00CC2F00);
	else if (i % 10 == 1)
		return (0x00DB6600);
	else if (i % 10 == 2)
		return (0x00E39E00);
	else if (i % 10 == 3)
		return (0x0076B80D);
	else if (i % 10 == 4)
		return (0x00007668);
	else if (i % 10 == 5)
		return (0x00006486);
	else if (i % 10 == 6)
		return (0x00007CB5);
	else if (i % 10 == 7)
		return (0x00465AB2);
	else if (i % 10 == 8)
		return (0x006D47B1);
	else
		return (0x00873B9C);
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
