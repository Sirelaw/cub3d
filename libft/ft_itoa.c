/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:37:13 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/21 15:21:04 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getnumlen(int n)
{
	int	numlen;

	numlen = 0;
	if (n < 0)
	{
		numlen++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		numlen++;
	}
	return (numlen);
}

char	*ft_itoa(int n)
{
	int		numlen;
	char	*chardigits;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	numlen = getnumlen(n);
	chardigits = (char *) malloc(numlen + 1);
	if (chardigits == NULL)
		return (NULL);
	chardigits[numlen--] = '\0';
	if (n < 0)
	{
		chardigits[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		chardigits[numlen--] = '0' + (n % 10);
		n = n / 10;
	}
	return (chardigits);
}
