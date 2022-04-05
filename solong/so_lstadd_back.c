#include "so_long.h"

int	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map	*temp;

	if (new == 0)
		return (0);
	temp = *lst;
	if (temp == 0)
	{
		*lst = new;
		return (1);
	}
	(*ft_lstlast(temp)).next = new;
	return (1);
}
