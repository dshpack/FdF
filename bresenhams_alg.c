/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:26:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 04:26:34 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int x)
{
	return (x > 0 ? x : -(x));
}

int		ft_max(int length_x, int length_y)
{
	if (length_x >= length_y)
		return (length_x);
	return (length_y);
}

void	image_maker(t_map *map, int x, int y, int c)
{
	if (x >= 0 && y >= 0 && x < map->width && y < map->height)
		map->draw.address[x + y * map->width] = c;
}

void	first_way(t_map *map, int color)
{
	int		x;
	int		y;
	int		d;

	x = map->draw.x1;
	y = map->draw.y1;
	d = -map->draw.length_x;
	map->draw.length++;
	while (map->draw.length--)
	{
		image_maker(map, x, y, color);
		x += map->draw.dx;
		d += 2 * map->draw.length_y;
		if (d > 0)
		{
			d -= 2 * map->draw.length_x;
			y += map->draw.dy;
		}
	}
}

void	second_way(t_map *map, int color)
{
	int		x;
	int		y;
	int		d;

	x = map->draw.x1;
	y = map->draw.y1;
	d = -map->draw.length_y;
	map->draw.length++;
	while (map->draw.length--)
	{
		image_maker(map, x, y, color);
		y += map->draw.dy;
		d += 2 * map->draw.length_x;
		if (d > 0)
		{
			d -= 2 * map->draw.length_y;
			x += map->draw.dx;
		}
	}
}
