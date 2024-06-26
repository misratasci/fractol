/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:13:40 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/26 17:19:21 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	app_init(t_app *app, int argc, char **argv)
{
	app->win_size = 1000;
	app->offset_x = app->win_size / 2;
	app->offset_y = app->win_size / 2;
	app->mlx = mlx_init();
	app->mlx_win = mlx_new_window(app->mlx, app->win_size,
			app->win_size, "Fractol");
	app->img.img = mlx_new_image(app->mlx, app->win_size, app->win_size);
	app->img.addr = mlx_get_data_addr(app->img.img, &app->img.bits_per_pixel,
			&app->img.line_length, &app->img.endian);
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
	app->max_iter = 50;
	if (argc == 3 && app->fractal == 'm')
		app->max_iter = ft_atoi(argv[2]);
	if (argc == 5 && app->fractal == 'j')
		app->max_iter = ft_atoi(argv[4]);
}

void	print_usage(void)
{
	write(1, "Usage:\nMandelbrot:\n\t./fractol m\n", 33);
	write(1, "\t./fractol m [max_iter]\n", 25);
	write(1, "Julia:\n\t./fractol j [Re(c)] [Im(c)]\n", 37);
	write(1, "\t./fractol j [Re(c)] [Im(c)] [max_iter]\n", 41);
	write(1, "(default max_iter: 50)\n", 24);
}

void	check_args(int argc, char **argv)
{
	if (argc <= 1 || argc > 5
		|| ((argc == 2 || argc == 3) && !valid_fractal(argv[1], 'm'))
		|| ((argc == 4 || argc == 5) && !valid_fractal(argv[1], 'j')))
	{
		print_usage();
		exit(EXIT_SUCCESS);
	}
	if ((argc == 3 && !valid_int(argv[2]))
		|| (argc == 5 && !valid_int(argv[4])))
	{
		write(1, "Int parse error\n", 17);
		print_usage();
		exit(EXIT_SUCCESS);
	}
	if (argc == 4 && valid_fractal(argv[1], 'j'))
	{
		if (!valid_double(argv[2]) || !valid_double(argv[3]))
		{
			write(1, "Double parse error\n", 20);
			print_usage();
			exit(EXIT_SUCCESS);
		}
	}
}

int	main(int argc, char **argv)
{
	t_app	*app;

	check_args(argc, argv);
	app = malloc(sizeof(t_app));
	if (!app)
	{
		perror("Could not allocate memory for app\n");
		exit(EXIT_FAILURE);
	}
	app_init(app, argc, argv);
	draw(app);
	mlx_hook(app->mlx_win, 04, 0, handle_mousewheel, app);
	mlx_hook(app->mlx_win, 17, 0, handle_destroy, app);
	mlx_hook(app->mlx_win, 02, 0, handle_esc, app);
	mlx_loop(app->mlx);
}
