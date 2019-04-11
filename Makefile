# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshpack <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 17:25:56 by dshpack           #+#    #+#              #
#    Updated: 2018/07/17 17:26:00 by dshpack          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS := -Wall -Werror -Wextra -O3

SRC := fdf.c validator.c initialization.c screen_initialization.c bresenhams_alg.c \
	waymark.c color_handler.c event_handler.c error_handler.c for_draw.c draw.c \
	cleaning_before_exit.c

HEAD := df.h

OBJ := $(SRC:.c=.o)

LIB := ./libft/libft.a

MLX := -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGS) -I $(HEAD) -c $(SRC)
	@gcc $(FLAGS) $(LIB) $(MLX) -o $(NAME) $(OBJ)
	@echo "\033[92mDONE\033[0m"

$(OBJ): %.o: %.c
	gcc $(FLAGS) -I $(HEAD) -c $< -o $@

clean:
	@make -C libft clean
	@/bin/rm -f $(OBJ)
	@echo "\033[92mObject files have been deleted\033[0m"

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)
	@echo "\033[92mExecutables have been deleted\033[0m"

re: fclean all

.PHONY:all clean fclean re