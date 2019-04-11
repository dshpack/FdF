/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 21:12:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/09/28 04:36:22 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define PI 3.14159265359
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

enum				e_keys
{
	SCALE_PLUS = 24,
	SCALE_MINUS = 27,
	SCALE_Z_PLUS = 69,
	SCALE_Z_MINUS = 78,
	ROTATE_X_PLUS = 12,
	ROTATE_X_MINUS = 0,
	ROTATE_Y_PLUS = 13,
	ROTATE_Y_MINUS = 1,
	ROTATE_Z_PLUS = 14,
	ROTATE_Z_MINUS = 2,
	PUSH_TO_LEFT = 123,
	PUSH_TO_RIGHT = 124,
	PUSH_TO_TOP = 126,
	PUSH_TO_BOTTOM = 125,
	BACK_TO_START = 51,
	CHANGE_COLOR = 49,
	MENU_DRAW = 46,
	DRAW_WMK = 36,
	ESCAPE = 53
};

typedef struct		s_pixel
{
	int				z;
	int				o_color;
}					t_pixel;

typedef struct		s_data_frame
{
	double			o_scale_x;
	double			o_scale_y;
	double			o_scale_z;
	double			o_push_x;
	double			o_push_y;
	double			push_x;
	double			push_y;
	double			rot_angle_x;
	double			rot_angle_y;
	double			rot_angle_z;
}					t_frame;

typedef struct		s_data_rotate
{
	double			x_0;
	double			y_0;
	double			z_0;
	double			x_1;
	double			y_1;
	double			z_1;
	double			x_2;
	double			y_2;
	double			x_3;
	double			y_3;
}					t_rotate;

typedef struct		s_data_draw
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				length;
	int				length_x;
	int				length_y;
	int				color;
	int				wmk_draw;
	int				menu_draw;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*address;
	int				bpp;
	int				s_line;
	int				endian;
}					t_draw;

typedef struct		s_waymark
{
	int				color[3];
	int				coord[4][2];
	int				str;
	double			x_0;
	double			y_0;
	double			x_1;
	double			y_1;
	double			x_2;
	double			y_2;
	double			x_3;
	double			y_3;
}					t_way_mrk;

typedef struct		s_map
{
	int				width;
	int				height;
	int				ver;
	int				hor;
	int				max_z;
	t_frame			frame;
	t_pixel			**coords;
	t_rotate		rot;
	t_draw			draw;
	t_way_mrk		wmk;
}					t_map;

int					check_line(char *line);
void				print_error_and_close(int flag);
t_map				*make_map(int ver, int hor);
int					check_file(int *ver, int *hor, int fd);
int					ft_atoi_ptr(int *i, char *str, int *color);
int					set_color(char *str, int *i, int *color);
void				del_map_and_exit(t_map *map, int error_flag);
void				set_screen_size(int argc, char *str, t_map *map);
void				calc_scale(t_map *map);
void				draw_xyz(t_map *map);
void				draw_waymark_frame(t_map *map);
void				draw_waymark(t_map *map);
int					ft_abs(int x);
int					ft_max(int length_x, int length_y);
void				image_maker(t_map *map, int x, int y, int c);
void				first_way(t_map *map, int color);
void				second_way(t_map *map, int color);
void				line(t_map *map, int color);
int					event_x(t_map *map);
int					event_handler(int key, t_map *map);
void				try_to_draw(t_map *map);
void				draw_menu_rectangle(t_map *map);
void				draw_menu_info(t_map *map);
void				draw_main(t_map *map);
void				put_message(int message);
void				ptr_freashing(t_map *map);

#endif
