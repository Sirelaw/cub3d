/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:51:48 by oipadeol          #+#    #+#             */
/*   Updated: 2022/01/06 22:01:21 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

int	check_equal_size(t_list *input)
{
	int		len;
	t_node	*elem;

	elem = (t_node *)(input->content);
	len = node_lstsize(elem);
	while (input != NULL)
	{
		elem = input->content;
		if (node_lstsize(elem) != len)
			ft_error();
		input = input->next;
	}
	return (1);
}

t_node	*str_to_row(char *map_string, int row_n)
{
	int		i;
	int		col_n;
	char	**ch;
	t_node	*t_row;

	i = 0;
	ch = ft_split(map_string, ' ');
	if (ch == NULL)
		return (NULL);
	while (ch[i])
		i++;
	if (*(ch[i - 1]) == '\n')
		ch[--i] = NULL;
	i = 0;
	col_n = 0;
	t_row = create_new_node(ch[i++], row_n, col_n++);
	free(ch[i - 1]);
	while (ch[i++])
	{
		node_lstadd_back(&t_row, create_new_node(ch[i - 1], row_n, col_n++));
		free(ch[i - 1]);
	}
	free(ch);
	return (t_row);
}
