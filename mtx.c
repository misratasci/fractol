/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:43:21 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/22 19:04:26 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	**create_matrix(int size_x)
{
	int	**mtx;
	int	i;

	mtx = (int **)malloc(sizeof(int *) * size_x);
	if (!mtx)
		perror("Could not allocate mtx");
	i = 0;
	while (i < size_x)
	{
		mtx[i] = (int *)malloc(sizeof(int) * size_x);
		if (!mtx[i])
			perror("Could not allocate mtx[i]");
		i++;
	}
	return (mtx);
}
