/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:23:52 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/24 16:42:55 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_app {
	void	*mlx;
	void	*mlx_win;
	int		win_size;
	t_data	img;
	double	scale;
	int		offset_x;
	int		offset_y;
}	t_app;

//mandelbrot.c
int	get_mandelbrot_pixel(int x, int y, t_app app);

//hooks.c
int	handle_mousewheel(int button, int x, int y, t_app *app);
double	scale_x(int x, double scale, int offset);
double	scale_y(int y, double scale, int offset);

//mtx.c
int		**create_matrix(int size_x);

//utils.c
int	get_color(int i, int max_iter);
void	fill_image(int size_x, t_data *img, t_app app);

#endif