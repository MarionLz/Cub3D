NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc -Imlx_linux -O3

SRC_DIR = src/
OBJ_DIR = obj/

SRCS =	$(SRC_DIR)main.c $(SRC_DIR)init.c $(SRC_DIR)draw_pixels.c $(SRC_DIR)print_map.c $(SRC_DIR)player.c $(SRC_DIR)error_exit.c \
		$(SRC_DIR)rays.c $(SRC_DIR)key.c $(SRC_DIR)draw_wall.c\

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