/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:16:47 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/24 17:03:33 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_app *app, double zoom_speed, int x, int y)
{
	double	new_scale;
	double	scale_ratio;

	new_scale = app->scale * (1 + zoom_speed);
	scale_ratio = new_scale / app->scale;
	app->offset_x = scale_ratio * (app->offset_x - x) + x;
	app->offset_y = scale_ratio * (app->offset_y - y) + y;
	app->scale = new_scale;
}

void	zoom_out(t_app *app, double zoom_speed, int x, int y)
{
	double	new_scale;
	double	scale_ratio;

	new_scale = app->scale * (1 - zoom_speed);
	scale_ratio = new_scale / app->scale;
	app->offset_x = scale_ratio * (app->offset_x - x) + x;
	app->offset_y = scale_ratio * (app->offset_y - y) + y;
	app->scale = new_scale;
}

int	handle_mousewheel(int button, int x, int y, t_app *app)
{
    if (button == 4)
    {
        printf("Mouse wheel up\n");
		printf("%f\n", app->scale);
		printf("x: %d, y: %d\n", x, y);
		zoom_in(app, 0.15, x, y);
		fill_image(app->win_size, &(app->img), *app);
		mlx_put_image_to_window(app->mlx, app->mlx_win, app->img.img, 0, 0);
    }
    else if (button == 5)
    {
        printf("Mouse wheel down\n");
		printf("%f\n", app->scale);
		printf("x: %d, y: %d\n", x, y);
		zoom_out(app, 20.0, x, y);
		fill_image(app->win_size, &(app->img), *app);
		mlx_put_image_to_window(app->mlx, app->mlx_win, app->img.img, 0, 0);
    }
	return (0);
}

double	scale_x(int x, double scale, int offset)
{
	return ((x - offset) / scale);
}

double	scale_y(int y, double scale, int offset)
{
	return ((offset - y) / scale);
}