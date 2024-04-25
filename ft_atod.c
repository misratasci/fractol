/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:40:10 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/25 12:13:43 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	count_in_str(const char *s, char c)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == c)
			c++;
		i++;
	}
	return (c);
}

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

double	ft_atod(const char *s)
{
	char 	**ss;
	double	divisor;
	char	*joined_str;
	double	joined;
	int		i;
	
	if (char_in_str(s, '.') == 0)
		return ((double)ft_atoi(s));
	if (char_in_str(s, '.') != 1)
	{
		perror("double parse error");
		exit(EXIT_FAILURE);
	}
	ss = ft_split(s, '.');
	i = 0;
	divisor = pow(10, ft_strlen(s));
	joined_str = ft_strjoin(ss[0], ss[1]);
	if (ss[0])
		free(ss[0]);
	if (ss[1])
		free(ss[1]);
	joined = (double)ft_atoi(joined_str);
	return (joined / divisor);
}