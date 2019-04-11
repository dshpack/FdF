/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:18:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 02:19:06 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_frame(t_map *map)
{
	map->frame.o_scale_x = 0;
	map->frame.o_scale_z = 0.2;
	map->frame.o_push_x = 0;
	map->frame.o_push_y = 0;
	map->frame.push_x = 0;
	map->frame.push_y = 0;
	map->draw.color = 1;
	map->frame.rot_angle_x = -0.1;
	map->frame.rot_angle_y = 6.2;
	map->frame.rot_angle_z = 0;
}

void		init_draw(t_map *map)
{
	map->draw.x1 = 0;
	map->draw.x2 = 0;
	map->draw.y1 = 0;
	map->draw.y2 = 0;
	map->max_z = 0;
	map->draw.wmk_draw = 0;
	map->draw.menu_draw = 0;
	init_frame(map);
}

int			init_ver_value(t_map *map)
{
	int		i;

	i = -1;
	if (map)
	{
		while (++i < map->ver)
			map->coords[i] = NULL;
		return (0);
	}
	return (1);
}

t_map		*make_map(int ver, int hor)
{
	int		i;
	int		j;
	t_map	*map;

	i = -1;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		print_error_and_close(1);
	map->ver = ver;
	map->hor = hor;
	init_draw(map);
	if (!(map->coords = (t_pixel **)malloc(sizeof(t_pixel *)
		* ver)) || init_ver_value(map))
		print_error_and_close(1);
	while (++i < ver)
	{
		if (!(map->coords[i] = (t_pixel *)malloc(sizeof(t_pixel) * hor)))
			del_map_and_exit(map, 1);
		j = -1;
		while (++j < hor)
		{
			map->coords[i][j].z = 0;
			map->coords[i][j].o_color = 0;
		}
	}
	return (map);
}
