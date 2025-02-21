# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 22:11:19 by rvikrama          #+#    #+#              #
#    Updated: 2024/11/17 16:39:52 by rvikrama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror -I./include/

# MacOS-specific MLX flags
MLXFLAGS = -I/usr/local/include -Imlx -O3
MLXLIBS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft/
MLX_DIR = mlx/
UTILS_DIR = src/utils/

FILES = \
		src/game.c \
		src/graphics.c \
		src/so_long.c \
		src/map.c \
		src/utils.c \
		src/check.c \
		src/flood_fill.c \

OBJS = ${FILES:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o ${<:.c=.o}

compile_dep:
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)/libmlx.a .
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	echo "\n\n" $(OBJS) "\n\n"

$(NAME): compile_dep $(OBJS)
	$(CC) $(CFLAGS) $(MLXLIBS) $(OBJS) libft.a libmlx.a -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f libmlx.a
	rm -f libft.a

re: all

.PHONY: all clean fclean re
