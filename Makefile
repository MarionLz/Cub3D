# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 14:33:39 by malauzie          #+#    #+#              #
#    Updated: 2024/07/23 14:34:21 by malauzie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./inc -Imlx_linux -O3

SRC_DIR = src/
OBJ_DIR = obj/

SRCS =	$(SRC_DIR)main.c $(SRC_DIR)init_textures.c $(SRC_DIR)draw_pixels.c $(SRC_DIR)moves.c $(SRC_DIR)error_exit.c \
		$(SRC_DIR)raycasting.c $(SRC_DIR)key.c $(SRC_DIR)draw_wall.c $(SRC_DIR)parse_file.c $(SRC_DIR)parse_map.c $(SRC_DIR)parsing_utils_1.c\
		$(SRC_DIR)free.c $(SRC_DIR)raycasting_utils.c $(SRC_DIR)parsing_utils_2.c $(SRC_DIR)get_next_line.c\

OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C mlx_linux
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./mlx_linux/ -L./libft/ -lmlx -lXext -lX11 -lm -lft

clean:
	$(MAKE) -C mlx_linux clean
	$(MAKE) -C libft clean
	rm -rf $(OBJ_DIR) 

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: fclean all
