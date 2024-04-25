/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:16:47 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/25 11:37:09 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_app *app, int x, int y)
{
	double	new_scale;
	double	scale_ratio;

	new_scale = app->scale * (1 + app->zoom_speed);
	scale_ratio = new_scale / app->scale;
	app->offset_x = scale_ratio * (app->offset_x - x) + x;
	app->offset_y = scale_ratio * (app->offset_y - y) + y;
	app->scale = new_scale;
}

void	zoom_out(t_app *app, int x, int y)
{
	double	new_scale;
	double	scale_ratio;

	new_scale = app->scale * (1 - app->zoom_speed);
	scale_ratio = new_scale / app->scale;
	app->offset_x = scale_ratio * (app->offset_x - x) + x;
	app->offset_y = scale_ratio * (app->offset_y - y) + y;
	app->scale = new_scale;
}

int	handle_mousewheel(int button, int x, int y, t_app *app)
{
    if (button == 4)
    {
		zoom_in(app, x, y);
		draw(app);
    }
    else if (button == 5)
    {
		zoom_out(app, x, y);
		draw(app);
    }
	return (0);
}
