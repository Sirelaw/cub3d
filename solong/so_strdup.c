#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	size_t	strsize;
	char	*pointer;

	strsize = ft_strlen(s1);
	pointer = malloc((strsize + 1) * sizeof(char));
	if (pointer == 0)
		return (0);
	ft_strlcpy(pointer, s1, (strsize + 1));
	return (pointer);
}
