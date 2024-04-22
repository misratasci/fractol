/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:13:40 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/22 18:13:49 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_image(int size_x, int **mtx, t_data *img)
{
	int	x;
	int	y;
	int	pix;

	x = 0;
	while (x < size_x)
	{
		y = 0;
		while (y < size_x)
		{
			pix = (x * (img->bits_per_pixel / 8)) + (y * img->line_length);
			img->addr[pix] = mtx[x][y] & 0xFF;
			img->addr[pix + 1] = (mtx[x][y] >> 8) & 0xFF;
			img->addr[pix + 2] = (mtx[x][y] >> 16) & 0xFF;
			y++;
		}
		x++;
	}
}

int	main(void)
{
	int		win_size;
	int		**mtx;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	double	scale;

	win_size = 600;
	scale = (double)(win_size / 4);
	mtx = create_matrix(win_size);
	fill_matrix(mtx, win_size, scale);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, win_size, win_size, "Fractol");
	img.img = mlx_new_image(mlx, win_size, win_size);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	fill_image(win_size, mtx, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 04, 0, handle_mousewheel, &scale);
	mlx_loop(mlx);
}