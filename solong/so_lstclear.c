#include "so_long.h"

void	ft_lstclear(t_map **lst)
{
	t_map	*temp1;
	t_map	*temp2;

	temp1 = *lst;
	if (*lst == 0 )
		return ;
	while (temp1->next != 0)
	{
		temp2 = temp1->next;
		free(temp1->content);
		free(temp1);
		temp1 = temp2;
	}
	free(temp1->content);
	free(temp1);
	*lst = 0;
	return ;
}
