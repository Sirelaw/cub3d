/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:06:57 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/05 15:14:29 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	free_ret(char **ret)
{
	free(*ret);
	*ret = NULL;
}

void	join_ret_stat(char **ret, char stat[BUFFER_SIZE + 1], int i, int j)
{
	char	*temp;

	temp = malloc(i + j + 1);
	i = 0;
	j = 0;
	while ((*ret)[i])
	{
		temp[i] = (*ret)[i];
		i++;
	}
	while (stat[j])
	{
		temp[i + j] = stat[j];
		j++;
	}
	temp[i + j] = '\0';
	*stat = '\0';
	free(*ret);
	*ret = temp;
}

void	new_line_found(char **ret, char stat[BUFFER_SIZE + 1], int i, int j)
{
	char	*temp;

	temp = malloc(i + j + 2);
	i = 0;
	j = 0;
	while ((*ret)[i])
	{
		temp[i] = (*ret)[i];
		i++;
	}
	while (stat[j] != '\n')
	{
		temp[i + j] = stat[j];
		j++;
	}
	temp[i + j] = '\0';
	temp[i + j + 1] = '\0';
	i = 0;
	while (stat[j++])
		stat[i++] = stat[j];
	stat[i] = '\0';
	free(*ret);
	*ret = temp;
}

int	check_static(char **ret, char stat[BUFFER_SIZE + 1])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*ret)[i])
		i++;
	while (stat[j] && stat[j] != '\n')
		j++;
	if (stat[j] == '\n')
	{
		new_line_found(ret, stat, i, j);
		return (1);
	}
	else
		join_ret_stat(ret, stat, i, j);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	stat[BUFFER_SIZE + 1];
	char		*ret;
	int			i;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	ret = malloc(1);
	if (ret == NULL)
		return (NULL);
	*ret = '\0';
	i = 1;
	while (i)
	{
		if (check_static(&ret, stat))
			break ;
		i = read(fd, stat, BUFFER_SIZE);
		if (i < 0)
			break ;
		stat[i] = '\0';
	}
	if (*ret == '\0')
		free_ret(&ret);
	return (ret);
}
