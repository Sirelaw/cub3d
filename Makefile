# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 20:23:06 by oipadeol          #+#    #+#              #
#    Updated: 2022/04/06 14:59:45 by oipadeol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3d

# Color codes

RESET	= \033[0m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m

CC =	gcc

# Compiling flags
FLAGS = -Wall -Werror -Wextra

# Folders
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/

# Source files and object files
SRC_FILES =	main.c get_line/get_line.c input_handling/input_handling.c\
		input_handling/input_handling_2.c\

OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)get_line
	@mkdir -p $(OBJ_DIR)input_handling
	@mkdir -p $(OBJ_DIR)utils

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
	@echo "$(BLUE)updated $@$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(INC_DIR)/*.h
	@echo "$(YELLOW)\n      -> Building $(NAME) ...$(RESET)"
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(BLUE)......linking updated .o"
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# clean rule
clean:
	@echo "$(RED)***   Deleting all objects from $(NAME)   ...   ***$(RESET)"
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

# fclean rule
fclean: clean
	@echo "$(RED)***   Deleting executable file from $(NAME)   ...   ***$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

# re rule
re: fclean all