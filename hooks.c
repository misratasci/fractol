/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:16:47 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/22 18:17:22 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(double *scale, double zoom_speed)
{
	*scale += zoom_speed;
}

int	handle_mousewheel(int button)
{
    if (button == 4)
    {
        printf("Mouse wheel up\n");
    }
    else if (button == 5)
    {
        printf("Mouse wheel down\n");
    }
	return (0);
}

double	scale_x(int x, double scale, double offset)
{
	return ((x - offset) / scale);
}


void	zoom_out(double *scale, double zoom_speed)
{
	*scale -= zoom_speed;
}