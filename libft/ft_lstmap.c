/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:18:28 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/21 17:55:50 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*newlisthead;
	t_list	*newelem;
	t_list	*p;

	if (lst == NULL)
		return (NULL);
	p = lst;
	newlisthead = ft_lstnew(f(p->content));
	if (newlisthead == NULL)
		return (NULL);
	newelem = newlisthead;
	p = p->next;
	while (p != NULL)
	{
		newelem->next = ft_lstnew(f(p->content));
		p = p->next;
		newelem = newelem->next;
		if (newelem == NULL)
		{
			ft_lstclear(&newlisthead, del);
			return (NULL);
		}
	}
	newelem = NULL;
	return (newlisthead);
}
