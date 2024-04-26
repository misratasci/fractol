/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:03:14 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/26 17:05:45 by mitasci          ###   ########.fr       */
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

static int	int_in_limit(const char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if ((len > 10 && s[0] != '-') || (s[0] == '-' && len > 11))
		return (0);
	if (len == 10 && s[0] != '-' &&
		ft_strncmp(s, "2147483647", 10) > 0)
		return (0);
	if (len == 11 && s[0] == '-' &&
		ft_strncmp(s, "-2147483648", 11) > 0)
		return (0);
	return (1);
}

int	valid_int(const char *s)
{
	int	i;

	if (!int_in_limit(s))
		return (0);
	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_fractal(const char *s, char f)
{
	return (ft_strlen(s) == 1 && s[0] == f);
}