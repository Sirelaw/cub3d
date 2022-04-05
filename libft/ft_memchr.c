/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:39:13 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/21 18:25:43 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			uc;
	const unsigned char		*string;		

	string = (unsigned char *) s;
	uc = (unsigned char) c;
	if (n <= 0)
		return (NULL);
	i = 0;
	while ((string[i] != uc) && (i < (n - 1)))
		i++;
	if (string[i] == uc)
		return ((void *)(string + i));
	else
		return (NULL);
}
