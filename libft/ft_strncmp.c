/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:12:18 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/19 11:32:14 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (unsigned char *) string1;
	str2 = (unsigned char *) string2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && (i < n) && (str1[i] != '\0'))
		i++;
	if (i == n)
		i--;
	if (str1[i] == str2[i])
		return (0);
	if (str1[i] > str2[i])
		return (1);
	else
		return (-1);
}
