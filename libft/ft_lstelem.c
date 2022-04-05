/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:24:32 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/06 15:37:22 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstelem(t_list *lst, int n)
{
	t_list	*p;
	int		i;

	i = 0;
	p = lst;
	while ((p != NULL) && (i < n))
	{
		p = p->next;
		i++;
	}
	if (i == n)
		return (p);
	else
		return (NULL);
}
