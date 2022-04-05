/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:51:09 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/15 22:16:44 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	strlen;

	if (s == NULL)
		return ;
	i = 0;
	strlen = ft_strlen(s);
	while (i < strlen)
	{
		f(i, &s[i]);
		i ++;
	}
}
