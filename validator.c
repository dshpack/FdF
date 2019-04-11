/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:25:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 05:20:56 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		validate_my_color(int *i, int tmp, size_t len, char *line)
{
	if (line[*i - 3] != ',' || line[*i - 2] != '0' || line[*i - 1] != 'x')
		return (-1);
	while (line[*i])
	{
		if (((line[*i] >= 'A' && line[*i] <= 'F')
			|| (line[*i] >= 'a' && line[*i] <= 'f') || (line[*i] >= '0' &&
		line[*i] <= '9')) && tmp < 6 && *i < (int)len)
			(*i)++;
		else if (line[*i] == ' ')
			break ;
		else
			return (-1);
		tmp++;
		if (tmp > 6)
			return (-1);
	}
	return (0);
}

int		check_line(char *line)
{
	int		i;
	size_t	len;
	int		tmp;

	i = 0;
	len = ft_strlen(line);
	while (line[i] && i < (int)len)
	{
		if ((line[i] == '-' || line[i] == ' ' || line[i] == ','
			|| (line[i] >= '0' && line[i] <= '9')) && i < (int)len)
			i++;
		else if (line[i] == 'x' && i < (int)len)
		{
			tmp = 0;
			i++;
			if (validate_my_color(&i, tmp, (int)len, line) == -1)
				return (-1);
			i++;
		}
		else
			return (-1);
	}
	return (1);
}

int		check_file(int *ver, int *hor, int fd)
{
	int		res;
	int		gnl;
	char	*line;

	while (1)
	{
		if ((gnl = get_next_line(fd, &line)) < 1)
			return (gnl);
		if (*hor == 0)
			if ((*hor = my_ft_wordscount(line, ' ')) == 0)
			{
				ft_strdel(&line);
				return (-1);
			}
		if (*hor != my_ft_wordscount(line, ' '))
		{
			ft_strdel(&line);
			return (-1);
		}
		res = check_line(line);
		ft_strdel(&line);
		(*ver)++;
		if (res <= 0)
			return (res);
	}
}
