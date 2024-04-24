/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:16:47 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/24 15:28:22 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(double *scale, double zoom_speed)
{
	*scale += zoom_speed;
}

int	handle_mousewheel(int button, int x, int y, t_app *app)
{
    if (button == 4)
    {
        printf("Mouse wheel up\n");
		printf("%f\n", app->scale);
		printf("x: %d, y: %d\n", x, y);
		fill_image(app->win_size, &(app->img), app->scale + 10.0);
		mlx_put_image_to_window(app->mlx, app->mlx_win, app->img.img, 0, 0);
    }
    else if (button == 5)
    {
        printf("Mouse wheel down\n");
    }
	return (0);
}

double	scale_x(int x, double scale, double offset)
{
	return ((x - offset) / scale);
}


void	zoom_out(double *scale, double zoom_speed)
{
	*scale -= zoom_speed;
}