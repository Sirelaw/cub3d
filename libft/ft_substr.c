/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:52:12 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/22 12:41:35 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlenght;
	char	*substr;

	if (string == NULL)
		return (NULL);
	i = 0;
	strlenght = ft_strlen(string);
	if (len > (strlenght - start))
		len = strlenght - start;
	if (start > (strlenght + 1))
		len = 0;
	substr = (char *) malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while ((string[start + i] != '\0') && (i < len))
	{
		substr[i] = string[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
