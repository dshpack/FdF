/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:51:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 02:53:05 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	search_w_h(char *str, int i, int *width, int *height)
{
	int		tmp;

	tmp = 0;
	while (str[i] && (int)ft_strlen(str) > i)
	{
		if (str[i] != 'w' && str[i] != 'h' && str[i] != '-' && str[i] != ' ')
			put_message(2);
		if (str[i] == '-')
		{
			if (str[i + 1] && str[i + 1] == 'w')
			{
				*width != 0 ? put_message(2) : (i += 2);
				*width = ft_atoi_ptr(&i, str, &tmp);
			}
			else if (str[i + 1] && str[i + 1] == 'h' && *height == 0)
			{
				*height != 0 ? put_message(2) : (i += 2);
				*height = ft_atoi_ptr(&i, str, &tmp);
			}
			else
				put_message(2);
		}
		i++;
	}
}

void	set_screen_size(int argc, char *str, t_map *map)
{
	int	i;
	int	width;
	int	height;

	if (argc == 3)
	{
		i = 0;
		width = 0;
		height = 0;
		search_w_h(str, i, &width, &height);
		if ((width >= 450 && width <= 2560)
			&& (height >= 200 && height <= 1400))
		{
			map->width = width;
			map->height = height;
		}
		else
			put_message(2);
	}
	else
	{
		map->width = 1920;
		map->height = 1080;
		put_message(3);
	}
}
