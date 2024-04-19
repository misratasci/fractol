/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:03:14 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/19 18:04:08 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int i, int max_iter)
{
	if (i < max_iter / 5)
		return (0x00D3F8E2);
	if (i < 2 * max_iter / 2)
		return (0x00E4C1F9);
	if (i < 3 * max_iter / 2)
		return (0x00F694C1);
	if (i < 4 * max_iter / 2)
		return (0x00EDE7B1);
	return (0x00000000);
}