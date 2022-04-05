#include "so_long.h"

void	my_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}
