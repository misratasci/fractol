/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:13:40 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/25 11:40:41 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	app_init(t_app *app, char **argv)
{
	app->win_size = 600;
	app->offset_x = app->win_size / 2;
	app->offset_y = app->win_size / 2;
	app->mlx = mlx_init();
	app->mlx_win = mlx_new_window(app->mlx, app->win_size, app->win_size, "Fractol");
	app->img.img = mlx_new_image(app->mlx, app->win_size, app->win_size);
	app->img.addr = mlx_get_data_addr(app->img.img, &app->img.bits_per_pixel, &app->img.line_length,
								&app->img.endian);
	app->scale = (double)(app->win_size / 4);
	app->cx = 0.35;
	app->cy = 0.35;
	app->fractal = argv[1][0];
	if (app->fractal == 'j')
	{
		app->cx = ft_atod(argv[2]);
		app->cy = ft_atod(argv[3]);
	}
	app->zoom_speed = 0.10;
}

int	main(int argc, char **argv)
{
	t_app	*app;

	if (argc <= 1 || (argc == 2 && argv[1][0] != 'm')) //diğer şartları da ekle
    {
        write(1, "Usage:\nMandelbrot:\t./fractol m\nJulia:\t\t./fractol j <Re(c)> <Im(c)>\n", 68);
        return (0);
    }

	app = malloc(sizeof(t_app));
	if (!app)
	{
		perror("Could not allocate memory for app\n");
		exit(EXIT_FAILURE);
	}
	app_init(app, argv);
	draw(app);
	mlx_hook(app->mlx_win, 04, 0, handle_mousewheel, app);
	mlx_loop(app->mlx);
}