# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 12:31:37 by rvikrama          #+#    #+#              #
#    Updated: 2024/10/05 16:44:00 by rvikrama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
MAKE_LIB = ar -rcs
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checkers
SRC_DIR = src_files/

SRC_1 = src_files/push_swap/push_swap.c 

SRC_2 = src_files/push_swap/push_swap_algorithm.c \
		src_files/push_swap/ft_add_back.c \
		src_files/push_swap/ft_stack_new.c \
		src_files/push_swap/ft_check_utils.c \
		src_files/push_swap/ft_parse.c \
		src_files/push_swap/solver_utils_ab.c \
		src_files/push_swap/solver_utils_ba.c \
		src_files/push_swap/ft_rotate_and_push.c \
		src_files/push_swap/operations.c \
		src_files/push_swap/operations_2.c \
		src_files/push_swap/operations_3.c \
		src_files/push_swap/ft_check_dups.c \
		src_files/push_swap/ft_check_sorted.c \
		src_files/push_swap/ft_error_print.c \
		src_files/push_swap/ft_free.c \
		src_files/push_swap/lst_utils.c \
		src_files/push_swap/lst_utils_2.c \
		src_files/push_swap/ft_parse_args_quoted.c \
		src_files/push_swap/ft_list_arguments.c \
		src_files/push_swap/ft_check_args.c \
		src_files/push_swap/ft_sort_big.c \
		src_files/push_swap/ft_sort_three.c \
		src_files/push_swap/ft_rotate_type.c \
		
BONUS_SRC = src_files/checkers/checkers.c \
			src_files/checkers/checkers_utils.c \
			
			

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_2} ${BONUS_OBJ} 
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus