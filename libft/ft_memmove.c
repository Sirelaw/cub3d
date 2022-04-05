/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:14:06 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/22 12:28:51 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*lastd;
	const unsigned char	*lasts;

	i = 0;
	lastd = dst + len - 1;
	lasts = src + len - 1;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (i < len)
		{
			lastd[0 - i] = lasts[0 - i];
			i++;
		}
	}
	return (dst);
}
