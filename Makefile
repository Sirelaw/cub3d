# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 20:23:06 by oipadeol          #+#    #+#              #
#    Updated: 2022/04/14 20:18:24 by oipadeol         ###   ########.fr        #
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
		input_handling/input_handling_2.c image_handler/image_handler.c\
		raycast/plotline.c raycast/raycast.c utils/mlx_utils.c raycast/draw_rays.c\
		dev_utils/dev_utils.c input_handling/small_utils.c\

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
	@mkdir -p $(OBJ_DIR)image_handler
	@mkdir -p $(OBJ_DIR)raycast
	@mkdir -p $(OBJ_DIR)utils
	@mkdir -p $(OBJ_DIR)dev_utils

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)/*.h
	@gcc -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
	@echo "$(BLUE)updated $@$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@echo "$(YELLOW)\n      -> Building $(NAME) ...$(RESET)"
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(BLUE)......linking updated .o"
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

no: $(OBJ)
	@echo "$(YELLOW)\n      -> Building $(NAME) ...$(RESET)"
	@$(CC) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(BLUE)......linking updated .o"
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

1:
	./$(NAME) "./maps/map18.cub"
2:
	./$(NAME) "./maps/map17.cub"

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