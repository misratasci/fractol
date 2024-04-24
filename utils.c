/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:03:14 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/24 16:42:52 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int i, int max_iter)
{
	if (i < max_iter / 5)
		return (0x00D3F8E2);
	if (i < 2 * max_iter / 2)
		return (0x00E4C1F9);
	if (i < 3 * max_iter / 2)
		return (0x00F694C1);
	if (i < 4 * max_iter / 2)
		return (0x00EDE7B1);
	return (0x00000000);
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
			color = get_mandelbrot_pixel(x, y, app);
			img->addr[pix] = color & 0xFF;
			img->addr[pix + 1] = (color >> 8) & 0xFF;
			img->addr[pix + 2] = (color >> 16) & 0xFF;
			y++;
		}
		x++;
	}
}