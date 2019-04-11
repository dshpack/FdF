/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waymark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:08:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/27 16:51:41 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_waymark_frame(t_map *map)
{
	map->draw.x1 = map->width * 10 / 100;
	map->draw.x2 = 0;
	map->draw.y1 = map->height - 1 - map->width * 10 / 100;
	map->draw.y2 = map->height - 1 - map->width * 10 / 100;
	line(map, 16729344);
	map->draw.x1 = 0;
	map->draw.x2 = map->width * 10 / 100;
	map->draw.y1 = map->height - 1;
	map->draw.y2 = map->height - 1;
	line(map, 16729344);
	map->draw.x1 = map->width * 10 / 100;
	map->draw.x2 = map->width * 10 / 100;
	map->draw.y1 = map->height - 1;
	map->draw.y2 = map->height - 1 - map->width * 10 / 100;
	line(map, 16729344);
	map->draw.x1 = 0;
	map->draw.x2 = 0;
	map->draw.y1 = map->height - 1;
	map->draw.y2 = map->height - 1 - map->width * 10 / 100;
	line(map, 16729344);
	map->wmk.str = map->height - 1 - map->width * 10 / 100 - 20;
}

void		rotate_wmk(t_map *map, int x, int y, int flag)
{
	map->wmk.x_0 = x - map->width * 10 / 100 / 2;
	map->wmk.y_0 = y - (map->height - 1 - map->width * 10 / 100 / 2);
	map->wmk.x_1 = map->wmk.x_0;
	map->wmk.y_1 = map->wmk.y_0 * cos(map->frame.rot_angle_x - (-0.1));
	map->wmk.x_2 = map->wmk.x_1 * cos(map->frame.rot_angle_y - 6.2);
	map->wmk.y_2 = map->wmk.y_1;
	map->wmk.x_3 = (map->wmk.x_2 * cos(map->frame.rot_angle_z) - map->wmk.y_2
		* sin(map->frame.rot_angle_z));
	map->wmk.y_3 = (map->wmk.x_2 * sin(map->frame.rot_angle_z) + map->wmk.y_2
		* cos(map->frame.rot_angle_z));
	if (flag == 0)
	{
		map->draw.x1 = (int)(map->wmk.x_3 + (map->width * 10 / 100 / 2));
		map->draw.y1 = (int)(map->wmk.y_3 + (map->height - 1 - map->width
			* 10 / 100 / 2));
	}
	else
	{
		map->draw.x2 = (int)(map->wmk.x_3 + (map->width * 10 / 100 / 2));
		map->draw.y2 = (int)(map->wmk.y_3 + (map->height - 1 - map->width
			* 10 / 100 / 2));
	}
}

void		draw_xyz(t_map *map)
{
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr,
			0, map->wmk.str, 0xFF00, "x");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr,
			20, map->wmk.str, 0xFF0000, "y");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr,
			40, map->wmk.str, 0xFF, "z");
}

void		draw_waymark(t_map *map)
{
	int		i;

	i = 0;
	draw_waymark_frame(map);
	map->wmk.color[0] = 255;
	map->wmk.coord[0][0] = map->width * 10 / 100 / 2;
	map->wmk.coord[0][1] = map->height - 1 - map->width * 10 / 100 / 2;
	map->wmk.coord[1][0] = map->width * 10 / 100 / 4;
	map->wmk.coord[1][1] = map->height - 1 - map->width * 10 / 100 / 4;
	map->wmk.color[1] = 16711680;
	map->wmk.coord[2][0] = map->width * 10 / 100;
	map->wmk.coord[2][1] = map->height - 1 - map->width * 10 / 100 / 2;
	map->wmk.color[2] = 65280;
	map->wmk.coord[3][0] = map->width * 10 / 100 / 2;
	map->wmk.coord[3][1] = map->height - 1 - map->width * 10 / 100;
	while (++i < 4)
	{
		rotate_wmk(map, map->wmk.coord[0][0], map->wmk.coord[0][1], 0);
		rotate_wmk(map, map->wmk.coord[i][0], map->wmk.coord[i][1], 1);
		line(map, map->wmk.color[i - 1]);
	}
}
