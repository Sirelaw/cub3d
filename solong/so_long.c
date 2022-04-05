#include "so_long.h"
//#include "../mini_mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h> //malloc
#include <unistd.h>  //read
#include <fcntl.h> // open

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc == 2)
	{
		i = 1;
		while (argv[1][i] != '.')
			i++;
		if (argv[1][i + 1] == 'c' && argv[1][i + 2] == 'u'
			&& argv[1][i + 3] == 'b' && argv[1][i + 4] == '\0')
		{
			fd = open(argv[1], O_RDONLY);
			if (fd < 0)
				perror("Error\nFailed to open file\n");
			else
				proc_file(fd);
			if (close(fd) < 0)
				perror("Error\nFailed to close file\n");
		}
	}
	return (0);
}

// system("leaks my_test.out");
//	fscanf(stdin, "c");