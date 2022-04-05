#include "so_long.h"

void	ft_lstadd_front(t_map **lst, t_map *new)
{
	(*new).next = *lst;
	*lst = new;
}
