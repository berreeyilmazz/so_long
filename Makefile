# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 18:54:37 by havyilma          #+#    #+#              #
#    Updated: 2023/03/19 14:26:04 by havyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I./minilibx
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
LIBFT = -I./libft
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNLOBJS = $(GNL:.c=.o)
SRCS = check_the_map.c main.c put_xpm.c  
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
	make bonus -C libft
	make -C ./minilibx

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc $(CFLAGS) $(OBJS) $(GNLOBJS) $(LFLAGS) ./libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./get_next_line/*.o
	make clean -C ./minilibx
	make fclean -C ./libft

re : fclean all

.PHONY: all clean fclean re
