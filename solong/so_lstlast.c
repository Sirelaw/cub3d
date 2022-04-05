#include "so_long.h"

t_map	*ft_lstlast(t_map *lst)
{
	if (lst == NULL)
		return (0);
	while ((*lst).next != NULL)
		lst = lst -> next;
	return (lst);
}
