/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:13:40 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/17 14:43:21 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_x(int x, int size_x)
{
	double offset;
	double	scale;

	offset = (double)size_x / 2;
	scale = (double)size_x / 4;
	return ((x - offset) / scale);
}

double	scale_y(int y, int size_y)
{
	return (-scale_x(y, size_y));
}

int	get_mandelbrot_pixel(int x, int y, int size_x, int size_y)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int		i;
	int		max_iter;

	c[0] = scale_x(x, size_x);
	c[1] = scale_y(y, size_y);
	z[0] = 0;
	z[1] = 0;
	i = 0;
	max_iter = 50;
	//printf("c = %f + %fi\n", c[0], c[1]);
	while (z[0] * z[0] + z[1] * z[1] <= 4 && i < max_iter)
	{
		//printf("z = %f + %fi, x2 + y2 = %f, i = %d\n", z[0], z[1], z[0] * z[0] + z[1] * z[1], i);
		tmp = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = tmp;
		i++;
	}
	if (i == max_iter)
		return (0x00FF0000);
	return (0x00000000);
}

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
	}
	return (mtx);
}

void	fill_matrix(int **mtx, int size_x, int size_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size_x)
	{
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
	j = 0;
	while (i < size_x)
	{
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
	
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		**mtx;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 200, 100, "Hello world!");
	img.img = mlx_new_image(mlx, 200, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mtx = create_matrix(200, 100);
	fill_matrix(mtx, 200, 100);
	//put_pixels(mlx, mlx_win, 200, 100, mtx);
	mlx_pixel_put(mlx, mlx_win, 10, 10, 0x0000FF00);
	mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF00FF);
	mlx_loop(mlx);
	
	printf("%d", get_mandelbrot_pixel(1000, 550, 2000, 1000));
}