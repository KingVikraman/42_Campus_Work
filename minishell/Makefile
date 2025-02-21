# Project name
NAME = minishell

# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
READLINE = -lreadline

# Directories
HEAD = ./includes/
INCLUDES = ./includes/minishell.h
SRC_DIR = ./srcs

# Recursive wildcard function
rwildcard = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

# Source files - recursively find all .c files
SRC = $(call rwildcard,$(SRC_DIR),*.c)

# Object files
OBJS = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Link the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(HEAD) -lncurses $(OBJS) -o $(NAME) $(READLINE)

# Compile source files
%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -I$(HEAD) -c $< -o $@

# Install readline dependency
readline:
	sudo apt-get install libreadline-dev

# Clean object files
clean:
	$(RM) $(OBJS)

# Clean all generated files
fclean: clean
	$(RM) $(NAME)

# Rebuild the project
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re readline
