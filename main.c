/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:13:40 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/24 16:43:08 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_app	*app;

	app = malloc(sizeof(t_app));
	printf("%p\n", &app);
	
	if (!app)
		perror("Could not allocate memory for app\n");
	
	app->win_size = 600;
	app->offset_x = app->win_size / 2;
	app->offset_y = app->win_size / 2;
	app->mlx = mlx_init();
	app->mlx_win = mlx_new_window(app->mlx, app->win_size, app->win_size, "Fractol");
	app->img.img = mlx_new_image(app->mlx, app->win_size, app->win_size);
	app->img.addr = mlx_get_data_addr(app->img.img, &app->img.bits_per_pixel, &app->img.line_length,
								&app->img.endian);
	app->scale = (double)(app->win_size / 4);
	fill_image(app->win_size, &(app->img), *app);
	mlx_put_image_to_window(app->mlx, app->mlx_win, app->img.img, 0, 0);
	mlx_hook(app->mlx_win, 04, 0, handle_mousewheel, app);
	mlx_loop(app->mlx);
}