/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:02:13 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/22 11:38:06 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*newstr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while ((ft_strchr(set, *s1)) && s1[0] != '\0')
		s1++;
	if (s1[0] == '\0')
		return (ft_strdup("\0"));
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i - 1]))
		i--;
	newstr = ft_substr(s1, 0, i);
	return (newstr);
}
