/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_before_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 05:08:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 19:05:55 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		del_map_and_exit(t_map *map, int error_flag)
{
	int		i;

	i = -1;
	if (map)
	{
		while (++i < map->ver)
		{
			free(map->coords[i]);
			map->coords[i] = NULL;
		}
		free(map->coords);
		map->coords = NULL;
		free(map);
		map = NULL;
		if (error_flag == 1)
			print_error_and_close(1);
	}
}

void		ptr_freashing(t_map *map)
{
	if (map->draw.mlx_ptr)
	{
		free(map->draw.mlx_ptr);
		map->draw.mlx_ptr = NULL;
	}
	if (map->draw.win_ptr)
	{
		free(map->draw.mlx_ptr);
		map->draw.mlx_ptr = NULL;
	}
	if (map->draw.img_ptr)
	{
		free(map->draw.img_ptr);
		map->draw.img_ptr = NULL;
	}
	if (map->draw.address)
	{
		free(map->draw.address);
		map->draw.address = NULL;
	}
	del_map_and_exit(map, 0);
}
