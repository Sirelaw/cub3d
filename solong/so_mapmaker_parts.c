#include "so_long.h"

static void	one_malloc(t_map **head, int x_size)
{
	char	*buffer;
	int		i;
	t_map	*new;

	i = -1;
	buffer = malloc(x_size * sizeof(char));
	if (!buffer)
		return ;
	while (++i < x_size - 1)
		buffer[i] = '1';
	buffer[i] = '\n';
	buffer[i + 1] = '\0';
	new = ft_lstnew(buffer);
	ft_lstadd_front(head, new);
}

// static void	let_maker(char let[4], char temp)
// {
// 	int	i;

// 	i = -1;
// 	if (temp == 'X')
// 	{
// 		while (++i < 4)
// 			let[i] = 0;
// 		let[i] = '\0';
// 	}
// 	if (temp == '1')
// 		let[3] += 1;
// 	if (temp == 'E')
// 		let[0] = 1;
// 	if (temp == 'P')
// 		let[1] = 1;
// 	if (temp == 'C')
// 		let[2] += 1;
// }

// static int	check_one(char *buffer, int x_size, char let[4], int size)
// {
// 	int	i;

// 	i = 0;
// 	if (size != 0 && buffer[0] == '1' && buffer[x_size - 2] == '1')
// 	{
// 		while (i < x_size)
// 		{
// 			if (ft_strchr("01P\n", buffer[i]))
// 				let_maker(let, buffer[i]);
// 			else
// 				return (0);  // 0
// 			i++;
// 		}
// 		if (buffer[x_size - 1] == '\n')
// 			return (0);   // 1
// 		// else if (let[3] == x_size - 1 && let[0] + let[1] == 2 && let[2] > 0)
// 		// 	return (1);
// 	}
// 	return (0);    // 0
// }

static void	mapmaker_two(int fd, int x_size, char let[4], t_map *head)
{
	char	*buffer;
	int		size;
	int		lines;

	size = 1;
	lines = 1;
	while (size)
	{
		let[3] = 0;
		buffer = malloc(x_size * sizeof(char));
		if (!buffer)
			return ;
		size = read(fd, buffer, x_size);
		buffer[size] = '\0';
		// if (check_one(buffer, x_size, let, size) != 0 && size != 0)
			lines += ft_lstadd_back(&head, ft_lstnew(ft_strdup(buffer)));
		// else if (size != 0)
		// {
		// 	perror("Error\nWrong map format here\n");
		// 	exit(EXIT_FAILURE);
		// }
		my_free(buffer);
	}
	game_starter(head, lines, x_size - 1);
}

void	proc_file(int fd)
{
	char		buf;
	int			i;
	static char	let[4];
	t_map		*head;

	i = 0;
	buf = '1';
	while (buf != '\n' && read(fd, &buf, 1) > 0 && buf == '1')
		i++;
	if (i > 3)
	{
		head = NULL;
		one_malloc(&head, i + 1);
		// let_maker(let, 'X');
		mapmaker_two(fd, i + 1, let, head);
	}
	else
	{
		perror("Error\nmap too small\n");
		exit(EXIT_FAILURE);
	}
}
