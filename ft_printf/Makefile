# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 13:32:57 by rvikrama          #+#    #+#              #
#    Updated: 2024/06/24 13:33:01 by rvikrama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .c -> o. -> .a

NAME =	libftprintf.a
AR	=	ar rcs
RM	=	rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf-hexdec.c \
		ft_printf-ptr.c \
		ft_printf-str.c \
		ft_printf-unsigned.c \
		ft_printf.c

OBJS			=	$(SRCS:%.c=%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

%.o: %.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME): $(LIBFT) $(OBJS)
	cp	$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
		make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean:	clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all bonus clean fclean re libft

