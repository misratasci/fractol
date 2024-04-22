/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:23:52 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/22 18:17:34 by mitasci          ###   ########.fr       */
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

typedef struct	s_grid {
	double	scale;
}	t_grid;

//mandelbrot.c
int	get_mandelbrot_pixel(int x, int y, int size_x, double scale);

//hooks.c
int	handle_mousewheel(int button);
double	scale_x(int x, double scale, double offset);

//mtx.c
int		**create_matrix(int size_x);
void	fill_matrix(int **mtx, int size_x, double scale);

//utils.c
int	get_color(int i, int max_iter);

#endif