/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:21:10 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/26 17:21:40 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	count_in_str(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	valid_double(const char *s)
{
	int	i;

	i = 0;
	if (count_in_str(s, '.') > 1 || s[ft_strlen(s) - 1] == '.')
		return (0);
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static int	int_in_limit(const char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if ((len > 10 && s[0] != '-') || (s[0] == '-' && len > 11))
		return (0);
	if (len == 10 && s[0] != '-'
		&& ft_strncmp(s, "2147483647", 10) > 0)
		return (0);
	if (len == 11 && s[0] == '-'
		&& ft_strncmp(s, "-2147483648", 11) > 0)
		return (0);
	return (1);
}

int	valid_int(const char *s)
{
	int	i;

	if (!int_in_limit(s))
		return (0);
	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_fractal(const char *s, char f)
{
	return (ft_strlen(s) == 1 && s[0] == f);
}
