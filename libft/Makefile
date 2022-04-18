# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 19:02:48 by oipadeol          #+#    #+#              #
#    Updated: 2022/04/10 11:51:29 by oipadeol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# # _*_ MakeFile _*_

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

OBJ_DIR = ./obj/

SRC = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isalnum.c ft_isascii.c\
		ft_isdigit.c ft_isascii.c ft_strlen.c ft_memset.c ft_memcpy.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
		ft_strdup.c ft_substr.c ft_strjoin.c ft_isprint.c ft_memmove.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_strcmp.c ft_strtol.c ft_bigger.c ft_absolute.c\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_lstmap.c ft_lstelem.c

OBJ_FILES = $(SRC:.c=.o)


OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: obj $(NAME)

$(OBJ_DIR)%.o:%.c
	@gcc -c $(FLAGS) $(SRC)
	@mv *.o $(OBJ_DIR)

$(NAME): $(OBJ)
	@ar -cr $(NAME) $(OBJ)
	@echo "libft library created."

obj:
	@mkdir -p $(OBJ_DIR)
	
clean:
	@rm -f $(OBJ)
	@echo "*.o files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "libft library deleted."

re: fclean all