#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	char	hold;
	char	*ncon;
	int		i;

	ncon = (char *)s;
	hold = (char)c;
	i = 0;
	while (ncon[i] != hold && ncon[i] != '\0')
		i++;
	if (ncon[i] == hold)
		return (&ncon[i]);
	else
		return (0);
}
