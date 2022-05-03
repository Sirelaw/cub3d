/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:44:30 by oipadeol          #+#    #+#             */
/*   Updated: 2022/05/03 13:23:30 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	do_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[0] == '\0')
		return (0);
	while (ft_strchr(" \n\t\v\f\r", str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while ((str[i] > 47) && (str[i] < 58))
	{
		num = (num * 10) + (str[i] - 48);
		if (num > INT32_MAX && (num * sign != INT32_MIN))
			ft_error("RGB value out of int range.");
		i++;
	}
	return (sign * num);
}

static int	convert_to_color(char *str)
{
	int		temp_color[3];
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(str, ',');
	if (temp == NULL)
		ft_error("Split call returned NULL in convert_to_color function.");
	while (temp && str)
	{
		str = temp[i++];
		while (str && *str)
			if (!ft_isdigit(*(str++)) || i > 3)
				ft_error("Wrong format for RGB input. (isdigit)");
	}
	i = 0;
	while (i++ < 3)
	{
		temp_color[i - 1] = do_atoi(temp[i - 1]);
		if (temp_color[i - 1] < 0 || temp_color[i - 1] > 255)
			ft_error("RGB value not in range of 0 - 255");
		free(temp[i - 1]);
	}
	free(temp);
	return (temp_color[0] << 16 | temp_color[1] << 8 | temp_color[2]);
}

void	assign_identifier(t_vars *vars, char **temp)
{
	if (temp && temp[0] && !ft_memcmp(temp[0], "NO", 3))
		vars->image[NO].path = temp[1];
	else if (temp && temp[0] && !ft_memcmp(temp[0], "SO", 3))
		vars->image[SO].path = temp[1];
	else if (temp && temp[0] && !ft_memcmp(temp[0], "WE", 3))
		vars->image[WE].path = temp[1];
	else if (temp && temp[0] && !ft_memcmp(temp[0], "EA", 3))
		vars->image[EA].path = temp[1];
	else if (temp && temp[0] && !ft_memcmp(temp[0], "EA", 3))
		vars->image[EA].path = temp[1];
	else if (temp && temp[0] && !ft_memcmp(temp[0], "F", 2))
		vars->floor_color = convert_to_color(temp[1]);
	else if (temp && temp[0] && !ft_memcmp(temp[0], "C", 2))
		vars->ceiling_color = convert_to_color(temp[1]);
	else
		ft_error("Element identifier not recognized.");
	if (temp && temp[0] && temp[1] && temp[2])
		ft_error("Non-map element has more than one space characters");
}

void	get_elements(t_vars *vars, int fd)
{
	int		skip;
	char	*elem;
	char	**temp;
	int		count;

	skip = 20;
	count = 0;
	while (skip-- && count < 6)
	{
		elem = get_line(fd);
		if (elem)
		{
			temp = ft_split(elem, ' ');
			if (temp == NULL)
				ft_error("Split call returned NULL in get_elememts");
			count++;
			assign_identifier(vars, temp);
			if (!ft_memcmp(temp[0], "F", 1) || !ft_memcmp(temp[0], "C", 1))
				if (temp[1])
					free(temp[1]);
			free(elem);
			free(temp[0]);
			free(temp);
		}
	}
}
