/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:25:00 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/21 18:23:38 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char) c;
	while ((s[i]) != '\0')
		i++;
	if (uc == '\0')
		return ((char *) &s[i]);
	while ((s[i] != uc) && (i > 0))
		i--;
	if (s[i] == uc)
		return ((char *) &s[i]);
	else
		return (NULL);
}
