/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:13:40 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/17 13:37:00 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_x(int x, int size_x)
{
	double offset;

	offset = (double)size_x / 2;
	return ((x - offset) / offset);
}

double	scale_y(int y, int size_y)
{
	return (-scale_x(y, size_y));
}
/*
int	**calculate_pixel(int x, int y)
{
	
}
*/
int	main(void)
{
	/*
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 2000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);
	mlx_loop(mlx);
	*/
	printf("%f", scale_y(450, 1000));
}