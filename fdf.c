/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:26:53 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 03:16:01 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_atoi_ptr(int *i, char *str, int *color)
{
	unsigned long int	res;
	int					sign;

	res = 0;
	sign = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-')
		sign = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
			&& (str[*i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
			&& (str[*i] - '0') > 8)) && sign == -1)
			return (0);
		res = res * 10 + (str[*i] - 48);
		(*i)++;
	}
	if (str[*i] == ',')
		*i = set_color(str, i, color);
	return ((int)res * sign);
}

void		set_coords(int i, int j, t_map *map, int fd)
{
	int		ii;
	int		color;
	char	*line;

	while (++i < map->ver)
	{
		j = -1;
		ii = 0;
		get_next_line(fd, &line);
		while (++j < map->hor)
		{
			color = 0;
			map->coords[i][j].z = ft_atoi_ptr(&ii, line, &color);
			if (map->coords[i][j].z > map->max_z)
				map->max_z = map->coords[i][j].z;
			if (color >= 0)
				map->coords[i][j].o_color = (color != 0) ? color : 4772300;
			else if (color == -1)
				del_map_and_exit(map, 0);
			ii++;
		}
		ft_strdel(&line);
	}
}

int			main(int argc, char **argv)
{
	int		ver;
	int		hor;
	int		fd;
	t_map	*map;

	if (argc > 1)
	{
		map = NULL;
		ver = 0;
		hor = 0;
		fd = open(argv[1], O_RDONLY);
		if (check_file(&ver, &hor, fd) < 0)
			print_error_and_close(0);
		if (hor <= 1 || ver <= 1)
			print_error_and_close(0);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		map = make_map(ver, hor);
		set_coords(-1, -1, map, fd);
		set_screen_size(argc, argv[2], map);
		try_to_draw(map);
	}
	else
		put_message(1);
	return (0);
}
