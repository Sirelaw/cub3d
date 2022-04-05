#include "so_long.h"

t_map	*ft_lstnew(void *staff)
{
	t_map	*temp;

	temp = malloc(sizeof(t_map));
	if (temp == NULL)
		return (0);
	else
	{
		(*temp).content = staff;
		(*temp).next = NULL;
		return (temp);
	}
}
