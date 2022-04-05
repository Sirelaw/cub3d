/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:11:34 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/22 12:52:38 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	int		i;
	int		strlen;

	if (s == NULL)
		return (NULL);
	i = 0;
	strlen = ft_strlen(s);
	newstr = malloc((strlen + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (i < strlen)
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[strlen] = '\0';
	return (newstr);
}
