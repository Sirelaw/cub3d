/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:42:32 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/21 18:23:57 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char) c;
	i = 0;
	while ((s[i] != uc) && (s[i] != '\0'))
		i++;
	if (s[i] == uc)
		return ((char *) &s[i]);
	else
		return (NULL);
}
