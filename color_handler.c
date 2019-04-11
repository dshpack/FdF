/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:21:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 02:21:56 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		calc_power(int pow, int num)
{
	int		rez;

	rez = num;
	if (num >= 0 && pow == 0)
		return (1);
	if (pow == 1)
		return (num);
	while (--pow)
		rez *= num;
	return (rez);
}

int		check_color(int *i, char *str)
{
	int		flag_size;

	flag_size = 0;
	if (str[*i] == ',' && str[(*i) + 1] == '0' && str[(*i) + 2] == 'x')
	{
		*i += 3;
		while (str[*i] != ' ' && str[*i])
		{
			(*i)++;
			flag_size++;
		}
		if (flag_size < 8)
			return (0);
	}
	return (-1);
}

int		set_color(char *str, int *i, int *color)
{
	int		pow;
	int		size;

	if ((pow = 0) || check_color(i, str) == -1)
		return (-1);
	size = *i;
	while (str[--(*i)] != 'x')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			*color += (str[*i] - 48) * (calc_power(pow, 16));
		else if (str[*i] == 'A' || str[*i] == 'a')
			*color += 10 * (calc_power(pow, 16));
		else if (str[*i] == 'B' || str[*i] == 'b')
			*color += 11 * (calc_power(pow, 16));
		else if (str[*i] == 'C' || str[*i] == 'c')
			*color += 12 * (calc_power(pow, 16));
		else if (str[*i] == 'D' || str[*i] == 'd')
			*color += 13 * (calc_power(pow, 16));
		else if (str[*i] == 'E' || str[*i] == 'e')
			*color += 14 * (calc_power(pow, 16));
		else if (str[*i] == 'F' || str[*i] == 'f')
			*color += 15 * (calc_power(pow, 16));
		pow++;
	}
	return (size);
}
