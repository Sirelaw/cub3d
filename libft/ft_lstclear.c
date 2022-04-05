/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:18:09 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/22 11:40:15 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*temp;

	temp = *lst;
	p = *lst;
	while (temp != NULL)
	{
		temp = p->next;
		ft_lstdelone(p, del);
		p = temp;
	}
	*lst = NULL;
}
