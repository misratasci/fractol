/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:43:21 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/19 17:43:59 by mitasci          ###   ########.fr       */
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