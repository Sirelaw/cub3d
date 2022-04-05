#ifndef SO_LONG_H
# define SO_LONG_H

# include "mini_mlx/mlx.h"
# include <stdio.h> //perror?
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	void			*content;
	struct s_map	*next;
}	t_map;

enum e_images
{
	FIG1,
	FIG2,
	FIG3,
	FIG4,
	FLOOR,
	BH1,
	BH2,
	BH3,
	BH4,
	WALL,
	EVA,
	MULI,
	FMULI,
	EXP1,
	EXP2,
	COUNT,
	COUBG,
	GOVER,
	WIN
};

enum e_nums
{
	ZER,
	ONE,
	TWO,
	TRE,
	FOU,
	FIV,
	SIX,
	SEV,
	EIG,
	NIN
};

typedef struct s_img
{
	void			*l;
	char			*p;
	enum e_images	name;
}	t_img;

typedef struct s_imgnum
{
	int				w;
	int				h;
	void			*l;
	char			*p;
	enum e_nums		name;
}	t_ium;

typedef struct s_vars
{
	t_img	im[19];
	t_ium	nu[10];
	void	*mlx;
	void	*win;
	int		count;
	char	**map;
	int		enemy;
	int		collect;
	int		check;
	int		fi_x;
	int		fi_y;
	int		bh_x;
	int		bh_y;
	int		b2_x;
	int		b2_y;
	int		wi_x;
	int		he_y;
}				t_vars;

//utils

void	ft_lstadd_front(t_map **lst, t_map *new);
int		ft_lstadd_back(t_map **lst, t_map *new);
void	ft_lstclear(t_map **lst);
t_map	*ft_lstlast(t_map *lst);
t_map	*ft_lstnew(void *staff);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	my_free(char *str);
void	game_starter(t_map *head, int lines, int rows);

//mapmaker
void	proc_file(int fd);

// mlx game related

void	img_handler(t_vars *game);
int		key_hook(int keycode, t_vars *game);
int		my_timer(t_vars *game);
void	put_num_screen(t_vars *game);
void	load_fields(t_map *head, t_vars *game);
void	my_killer(t_vars *game);

#endif
