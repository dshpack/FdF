/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 21:10:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 04:39:35 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_hendler(t_map *map, int flag)
{
	if (flag == 0)
	{
		map->draw.x1 = (int)(map->rot.x_3 * map->frame.o_scale_x
			+ map->frame.o_push_x);
		map->draw.y1 = (int)((map->rot.y_3 * map->frame.o_scale_x
			+ map->frame.o_push_y));
	}
	else
	{
		map->draw.x2 = (int)(map->rot.x_3 * map->frame.o_scale_x
			+ map->frame.o_push_x);
		map->draw.y2 = (int)((map->rot.y_3 * map->frame.o_scale_x
			+ map->frame.o_push_y));
	}
}

void		rotate(t_map *map, int x, int y, int flag)
{
	double z;

	z = map->coords[y][x].z;
	z != 0 ? z = z + map->frame.o_scale_z : 0;
	map->rot.x_0 = map->hor / 2;
	map->rot.y_0 = map->ver / 2;
	map->rot.z_0 = z / 2;
	map->rot.x_1 = x;
	map->rot.y_1 = map->rot.y_0 + (y - map->rot.y_0)
		* cos(map->frame.rot_angle_x) + (map->rot.z_0 - z)
		* sin(map->frame.rot_angle_x);
	map->rot.z_1 = map->rot.z_0 + (y - map->rot.y_0)
		* sin(map->frame.rot_angle_x) + (z - map->rot.z_0)
		* cos(map->frame.rot_angle_x);
	map->rot.x_2 = map->rot.x_0 + (map->rot.x_1 - map->rot.x_0)
		* cos(map->frame.rot_angle_y) + (map->rot.z_1 - map->rot.z_0)
		* sin(map->frame.rot_angle_y);
	map->rot.y_2 = map->rot.y_1;
	map->rot.x_3 = map->rot.x_0 + (map->rot.x_2 - map->rot.x_0)
		* cos(map->frame.rot_angle_z) + (map->rot.y_0 - map->rot.y_2)
		* sin(map->frame.rot_angle_z);
	map->rot.y_3 = map->rot.y_0 + (map->rot.x_2 - map->rot.x_0)
		* sin(map->frame.rot_angle_z) + (map->rot.y_2 - map->rot.y_0)
		* cos(map->frame.rot_angle_z);
	rotate_hendler(map, flag);
}

void		redraw_figure(t_map *map)
{
	int		y;
	int		x;

	y = -1;
	while (++y < map->ver)
	{
		x = -1;
		while (++x < map->hor)
		{
			if (x + 1 < map->hor)
			{
				rotate(map, x, y, 0);
				rotate(map, x + 1, y, 1);
				line(map, map->coords[y][x].o_color * map->draw.color);
			}
			if (y + 1 < map->ver)
			{
				rotate(map, x, y, 0);
				rotate(map, x, y + 1, 1);
				line(map, map->coords[y][x].o_color * map->draw.color);
			}
		}
	}
}

void		draw_main(t_map *map)
{
	ft_memset(map->draw.address, 0, (size_t)map->width * map->height * 4);
	if (map->draw.wmk_draw != 0)
		draw_waymark(map);
	redraw_figure(map);
	if (map->draw.menu_draw != 0)
		draw_menu_rectangle(map);
	mlx_put_image_to_window(map->draw.mlx_ptr,
		map->draw.win_ptr, map->draw.img_ptr, 0, 0);
	if (map->draw.wmk_draw != 0)
		draw_xyz(map);
	if (map->draw.menu_draw != 0)
		draw_menu_info(map);
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 20, 20, 0xFF4500,
		"menu on/off:");
	mlx_string_put(map->draw.mlx_ptr, map->draw.win_ptr, 240, 20, 0xFF4500,
		"m");
}

void		try_to_draw(t_map *map)
{
	map->draw.mlx_ptr = mlx_init();
	map->draw.win_ptr = mlx_new_window(map->draw.mlx_ptr,
		map->width, map->height, "FDF project by dshpack");
	map->draw.img_ptr =
		mlx_new_image(map->draw.mlx_ptr, map->width, map->height);
	map->draw.address = (int *)mlx_get_data_addr(map->draw.img_ptr,
		&map->draw.bpp, &map->draw.s_line, &map->draw.endian);
	calc_scale(map);
	draw_main(map);
	mlx_hook(map->draw.win_ptr, 17, 1L << 17, event_x, map);
	mlx_hook(map->draw.win_ptr, 2, 1L << 0, event_handler, map);
	mlx_loop(map->draw.mlx_ptr);
}
