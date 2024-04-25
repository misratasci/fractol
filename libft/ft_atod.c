/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:40:10 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/25 13:09:57 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	pow(a, b)
{
	int		i;
	double	res;

	i = 0;
	res = 1;
	while (i < b)
	{
		res *= a;
		i++;
	}
	return (res);
}

static void	free_ss(char **ss)
{
	if (ss[0])
		free(ss[0]);
	if (ss[1])
		free(ss[1]);
	if (ss)
		free(ss);
}

double	ft_atod(const char *s)
{
	char	**ss;
	double	divisor;
	char	*joined_str;
	double	joined;

	if (count_in_str(s, '.') == 0)
		return ((double)ft_atoi(s));
	if (s[0] != '.')
	{
		ss = ft_split(s, '.');
		divisor = pow(10, ft_strlen(ss[1]));
		joined_str = ft_strjoin(ss[0], ss[1]);
		free_ss(ss);
		joined = (double)ft_atoi(joined_str);
		if (joined_str)
			free(joined_str);
	}
	else
	{
		divisor = pow(10, ft_strlen(s) - 1);
		joined = (double)ft_atoi(s + 1);
	}
	return (joined / divisor);
}
