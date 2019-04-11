/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:35:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/27 22:19:49 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_message_screen(void)
{
	ft_putstr("\n==============================="
		"==================================\n");
	ft_putstr("= You did not set the screen size! "
		"                             =\n");
	ft_putstr("= The screen size will be set in default"
		" value: \"-w1920 -h1080\" =\n");
	ft_putstr("================================="
		"================================\n\n");
}

void		put_message(int message)
{
	if (message == 1)
	{
		ft_putstr("\n========================\n");
		ft_putstr("= File is not entered! =\n");
		ft_putstr("========================\n\n");
	}
	else if (message == 2)
	{
		ft_putstr("\n==============================="
			"===================================\n");
		ft_putstr("= Screen size is too small, or too big,"
			" or it have wrong format! =\n");
		ft_putstr("= Put your size as second argument, like"
		" \"-w1920 -h1080\"         =\n");
		ft_putstr("= Diapason should be between min 450x200"
		" and max 2560x1400       =\n");
		ft_putstr("================================="
			"=================================\n\n");
		exit(0);
	}
	else if (message == 3)
		put_message_screen();
}

void		print_error_and_close(int flag)
{
	if (flag == 0)
	{
		ft_putstr("\n==============================="
			"=======================\n");
		ft_putstr("= Sorry, file is not readable, or it is not correct! =\n");
		ft_putstr("================================="
			"=====================\n");
	}
	else if (flag == 1)
	{
		ft_putstr("\n================================"
			"======================\n");
		ft_putstr("=                 Sorry, memory low!                 =\n");
		ft_putstr("=================================="
			"====================\n");
	}
	exit(0);
}
