CC = gcc
NAME = cub3D
FLAGS = -Wall -Wextra -Werror -Lmini_mlx -lmlx -framework OpenGL -framework AppKit -lz
FLAGSNO = -Lmini_mlx -lmlx -framework OpenGL -framework AppKit -lz
PATHMLX = mini_mlx/
SRC = 	so_game_maker.c so_killer.c so_long.c so_lstadd_front.c so_lstlast.c so_mapmaker_parts.c\
		so_mykey_hook.c so_put_counter.c so_strdup.c so_strlen.c so_imghadler.c so_load_fields.c\
		so_lstadd_back.c so_lstclear.c so_lstnew.c so_myfree.c so_mytimer.c so_strchr.c so_strlcpy.c
ARG = "./maps/map03.ber"

all: $(NAME)

mlx:
	@make -C $(PATHMLX) all

$(NAME): mlx
	$(CC) -o $(NAME) $(FLAGS) $(SRC) -I./mini_mlx/

no: mlx
	$(CC) -o $(NAME) $(FLAGSNO) $(SRC) -I./mini_mlx/

clean:
	@make -C $(PATHMLX) clean
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

te:
	$(CC) -o $(TESTFNAME) $(FLAGS) $(SRC) -I./mini_mlx/

#-------------- Part test ------------------

begin: all test

#-------------- Part test ------------------

#question is there a way to onsert in to the libery only the changed object file?
#run the test executable
play:
	./$(NAME) $(ARG)

1:
	./$(NAME) "./maps/map18.cub"
2:
	./$(NAME) "./maps/map02.ber"
3:
	./$(NAME) "./maps/map03.ber"
4:
	./$(NAME) "./maps/map04.ber"
5:
	./$(NAME) "./maps/map05.ber"
6:
	./$(NAME) "./maps/map06.ber"