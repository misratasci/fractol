/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:45:00 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/25 11:12:57 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_julia_pixel(int x, int y, t_app app)
{
	double	z[2];
	double	z2[2];
	int		i;
	int		max_iter;

	z[0] = scale_x(x, app.scale, app.offset_x);
	z[1] = scale_y(y, app.scale, app.offset_y);

	z2[0] = z[0] * z[0];
	z2[1] = z[1] * z[1];
	i = 0;
	max_iter = 500;
	while (z2[0] + z2[1] <= 4 && i < max_iter)
	{
		z[1] = 2 * z[0] * z[1] + app.cy;
		z[0] = z2[0] - z2[1] + app.cx;
		z2[0] = z[0] * z[0];
		z2[1] = z[1] * z[1];
		i++;
	}
	return (get_color(i, max_iter));
}