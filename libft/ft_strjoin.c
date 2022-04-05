/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:22:52 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/12 22:21:21 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*newstr;

	k = 0;
	l = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	newstr = (char *) malloc(i + j + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[k])
	{
		newstr[k] = s1[k];
		k++;
	}
	while (s2[l])
	{
		newstr[k + l] = s2[l];
		l++;
	}
	newstr[k + l] = '\0';
	return (newstr);
}
