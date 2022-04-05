/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:45:00 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/15 23:02:28 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t c)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = dest;
	while (i < c)
	{
		ptr[i] = '\0';
		i++;
	}
}
