# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 18:54:37 by havyilma          #+#    #+#              #
#    Updated: 2023/03/23 05:51:53 by havyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I./minilibx
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNLOBJS = $(GNL:.c=.o)
SRCS = check_the_map.c so_long.c put_xpm.c ft_move.c ft_key_handler.c check_the_map_2.c ft_putnbbr.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
	make -C ./minilibx

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc $(CFLAGS) $(OBJS) $(GNLOBJS) $(LFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./get_next_line/*.o
	make clean -C ./minilibx

re : fclean all

.PHONY: all clean fclean re
