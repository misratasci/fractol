/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:13:40 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/19 16:19:28 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	**create_matrix(int size_x, int size_y)
{
	int	**mtx;
	int	i;

	mtx = (int **)malloc(sizeof(int *) * size_x);
	if (!mtx)
		perror("Could not allocate mtx");
	i = 0;
	while (i < size_x)
	{
		mtx[i] = (int *)malloc(sizeof(int) * size_y);
		if (!mtx[i])
			perror("Could not allocate mtx[i]");
		i++;
	}
	return (mtx);
}

void	fill_matrix(int **mtx, int size_x, int size_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_x)
	{
		j = 0;
		while (j < size_y)
		{
			mtx[i][j] = get_mandelbrot_pixel(i, j, size_x, size_y);
			j++;
		}
		i++;
	}
}

void	put_pixels(void *mlx, void *mlx_win, int size_x, int size_y, int **mtx)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_x)
	{
		j = 0;
		while (j < size_y)
		{
			mlx_pixel_put(mlx, mlx_win, i, j, mtx[i][j]);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int		win_size[2];
	int		**mtx;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	win_size[0] = 1000;
	win_size[1] = 1000;
	mtx = create_matrix(win_size[0], win_size[1]);
	fill_matrix(mtx, win_size[0], win_size[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, win_size[0], win_size[1], "Fractol");
	img.img = mlx_new_image(mlx, win_size[0], win_size[1]);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	put_pixels(mlx, mlx_win, win_size[0], win_size[1], mtx);
	mlx_hook(mlx_win, 04, 0, handle_mousewheel, NULL);
	mlx_loop(mlx);
}