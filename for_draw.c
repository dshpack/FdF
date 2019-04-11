/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:33:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 18:58:09 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calc_scale(t_map *map)
{
	if (map->hor < 100)
		map->frame.o_scale_x = map->width / 4 / 4 * 3 / (map->hor / 2);
	else
		map->frame.o_scale_x = map->width / 4 / 1.5 * 3 / (map->hor);
	if (map->ver < 100)
		map->frame.o_scale_y = map->height / 4 * 3 / (map->ver / 2);
	else
		map->frame.o_scale_y = map->height / 4 * 3 / (map->ver / 2);
	map->frame.o_push_x = map->width / 2 - (map->hor
		* map->frame.o_scale_x / 2) + map->frame.push_x;
	map->frame.o_push_y = map->height / 2 - (map->ver
		* map->frame.o_scale_x / 2) + map->frame.push_y;
}

void		draw_menu_rectangle(t_map *map)
{
	int		i;

	i = -1;
	while (++i < 195)
	{
		map->draw.x1 = 10;
		map->draw.y1 = 15 + i;
		map->draw.x2 = 430;
		map->draw.y2 = 20 + i;
		line(map, 0);
	}
}

void		draw_menu_info_helper(t_map *map)
{
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 20, 40, 0xFF4500,
		"move image:");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 240, 40, 0x6A5ACD,
		"left-right-up-down");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 20, 60, 0xFF4500,
		"scale image:");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 240, 60, 0x6A5ACD,
		"+ / -");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 20, 80, 0xFF4500,
		"scale only z:");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 240, 80, 0x6A5ACD,
		"+ / - (numpad)");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 20, 100, 0xFF4500,
		"rotate in X-Y-Z:");
}

void		draw_menu_info(t_map *map)
{
	draw_menu_info_helper(map);
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 240, 100, 0x6A5ACD,
		"q-a, w-s, e-d");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 20, 120, 0xFF4500,
		"change color:");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 240, 120, 0x6A5ACD,
		"space");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 20, 140, 0xFF4500,
		"axis compass on/off:");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 240, 140, 0x6A5ACD,
		"enter");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 20, 160, 0xFF4500,
		"reset changes:");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 240, 160, 0x6A5ACD,
		"Backspace");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 20, 180, 0x8B0000,
		"to escape:");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 240, 180, 0x8B0000,
		"ESC, or red cross");
}

void		line(t_map *map, int color)
{
	map->draw.dx = (map->draw.x2 - map->draw.x1 >= 0 ? 1 : -1);
	map->draw.dy = (map->draw.y2 - map->draw.y1 >= 0 ? 1 : -1);
	map->draw.length_x = ft_abs(map->draw.x2 - map->draw.x1);
	map->draw.length_y = ft_abs(map->draw.y2 - map->draw.y1);
	map->draw.length = ft_max(map->draw.length_x, map->draw.length_y);
	if (map->draw.length == 0)
		image_maker(map, map->draw.x1, map->draw.y1, color);
	if (map->draw.length_y <= map->draw.length_x)
		first_way(map, color);
	else
		second_way(map, color);
}
