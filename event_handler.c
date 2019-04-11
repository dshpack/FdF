/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:55:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 19:00:27 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		event_x(t_map *map)
{
	mlx_destroy_window(map->draw.mlx_ptr, map->draw.win_ptr);
	ptr_freashing(map);
	exit(1);
}

void	rotating_and_scaling(int key, t_map *map)
{
	if (key == ROTATE_X_PLUS)
		map->frame.rot_angle_x += 1.7 * PI / 180;
	if (key == ROTATE_X_MINUS)
		map->frame.rot_angle_x -= 1.7 * PI / 180;
	if (key == ROTATE_Y_PLUS)
		map->frame.rot_angle_y += 1.7 * PI / 180;
	if (key == ROTATE_Y_MINUS)
		map->frame.rot_angle_y -= 1.7 * PI / 180;
	if (key == ROTATE_Z_PLUS)
		map->frame.rot_angle_z += 1.7 * PI / 180;
	if (key == ROTATE_Z_MINUS)
		map->frame.rot_angle_z -= 1.7 * PI / 180;
	if (key == SCALE_PLUS)
		map->frame.o_scale_x += 0.9;
	if (key == SCALE_MINUS)
		map->frame.o_scale_x > 1 ? map->frame.o_scale_x -= 0.9 : 0;
	if (key == SCALE_Z_PLUS)
		if (map->frame.o_scale_z < 2147483647)
			map->frame.o_scale_z += 2;
	if (key == SCALE_Z_MINUS)
		if (map->frame.o_scale_z > -2147483648)
			map->frame.o_scale_z -= 2;
}

void	menu_wmk_pushes(int key, t_map *map)
{
	if (key == PUSH_TO_LEFT)
		map->frame.push_x -= 20;
	if (key == PUSH_TO_RIGHT)
		map->frame.push_x += 20;
	if (key == PUSH_TO_TOP)
		map->frame.push_y -= 20;
	if (key == PUSH_TO_BOTTOM)
		map->frame.push_y += 20;
	if (key == MENU_DRAW)
	{
		if (map->draw.menu_draw == 0)
			map->draw.menu_draw = 1;
		else
			map->draw.menu_draw = 0;
	}
	if (key == DRAW_WMK)
	{
		if (map->draw.wmk_draw == 0)
			map->draw.wmk_draw = 1;
		else
			map->draw.wmk_draw = 0;
	}
}

void	to_start(int key, t_map *map)
{
	if (key == BACK_TO_START)
	{
		calc_scale(map);
		map->frame.rot_angle_x = -0.1;
		map->frame.rot_angle_y = 6.2;
		map->frame.rot_angle_z = 0;
		map->frame.o_scale_z = 0.2;
		map->frame.push_x = 1;
		map->frame.push_y = 1;
		map->draw.color = 1;
	}
	if (key == ESCAPE)
	{
		mlx_destroy_window(map->draw.mlx_ptr, map->draw.win_ptr);
		ptr_freashing(map);
		exit(1);
	}
}

int		event_handler(int key, t_map *map)
{
	if (key == 24 || key == 27 || key == 69 || key == 78 || key == 12 ||
		key == 0 || key == 13 || key == 1 || key == 14 || key == 2)
		rotating_and_scaling(key, map);
	if (key == 124 || key == 123 || key == 126 || key == 125 ||
		key == 46 || key == 36)
		menu_wmk_pushes(key, map);
	if (key == 51 || key == ESCAPE)
		to_start(key, map);
	if (key == CHANGE_COLOR)
	{
		if (map->draw.color + 620 <= 2147483647)
			map->draw.color += 620;
		else
			map->draw.color = 1;
	}
	map->frame.o_push_x = map->width / 2
		- (map->hor * map->frame.o_scale_x / 2) + map->frame.push_x;
	map->frame.o_push_y = map->height / 2
		- (map->ver * map->frame.o_scale_x / 2) + map->frame.push_y;
	draw_main(map);
	return (0);
}
