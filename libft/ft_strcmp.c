/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:09:01 by oipadeol          #+#    #+#             */
/*   Updated: 2022/01/06 20:24:40 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *string1, const char *string2)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (unsigned char *) string1;
	str2 = (unsigned char *) string2;
	i = 0;
	while ((str1[i] == str2[i]) && (str1[i] != '\0'))
		i++;
	if ((str1[i] == str2[i]) && (str1[i] == '\0'))
		return (0);
	else
		return ((int) str1[i] - (int) str2[i]);
}
