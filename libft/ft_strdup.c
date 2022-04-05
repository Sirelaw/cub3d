/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:09:31 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/18 14:53:22 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string1)
{
	char	*string2;
	int		i;

	i = 0;
	while (string1[i] != '\0')
		i++;
	string2 = (char *) malloc(i + 1);
	if (string2 == NULL)
		return (NULL);
	i = 0;
	while (string1[i])
	{
		string2[i] = string1[i];
		i++;
	}
	string2[i] = '\0';
	return (string2);
}
