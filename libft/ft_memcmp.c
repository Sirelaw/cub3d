/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:48:00 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/22 12:38:21 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const char *string1, const char *string2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)string1;
	str2 = (unsigned char *)string2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && (i < (n - 1)))
		i++;
	if (str1[i] == str2[i])
		return (0);
	else
		return (str1[i] - str2[i]);
}
