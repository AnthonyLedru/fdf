/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:44:30 by aledru            #+#    #+#             */
/*   Updated: 2018/01/05 16:01:28 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_hexa(char *line)
{
	int	i;

	i = 0;
	line++;
	if (*line && *line != '0')
		exit(EXIT_FAILURE);
	line++;
	if (*line && *line != 'x')
		exit(EXIT_FAILURE);
	line++;
	while (*line != ' ')
	{
		if ((*line < 'A' || *line > 'F') && (*line < 'a' || *line > 'f') &&
				(*line < '0' || *line > '9'))
			exit(EXIT_FAILURE);
		line++;
		i++;
	}
	if (i == 0 || i > 6)
		exit(EXIT_FAILURE);
	return (i);
}

static void		check_line_valid(char *line)
{
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (*line == '-')
			line++;
		if (!*line || *line < '0' || *line > '9')
			exit(EXIT_FAILURE);
		while (*line != '\0' && *line >= '0' && *line <= '9')
			line++;
		if (*line == '\0')
			break ;
		if (*line == ',')
			line += check_hexa(&(*line)) + 3;
		if (*line == '\0')
			break ;
		if (*line && *line != ' ')
			exit(EXIT_FAILURE);
		while (*line && *line == ' ')
			line++;
	}
}

static	int		get_point_color(char *point)
{
	int		color;
	char	*color_point;

	if (ft_strchr(point, ','))
	{
		color_point = &ft_strchr(point, ',')[1];
		color = ft_htoi(color_point);
	}
	else
		color = 0xFFFFFF;
	return (color);
}

static t_line	*line_to_struct(char *line)
{
	static int		num;
	char			**all_values;
	t_line_values	**values;
	int				size;

	all_values = ft_strsplit(line, ' ');
	size = 0;
	while (all_values[size])
		size++;
	values = (t_line_values**)ft_memalloc(sizeof(t_line_values*) * size);
	while (size - 1 >= 0)
	{
		values[size - 1] = create_line_values(ft_atoi(all_values[size - 1]),
		get_point_color(all_values[size - 1]));
		free(all_values[size - 1]);
		size--;
	}
	while (all_values[size])
		size++;
	num++;
	free(all_values);
	return (create_line(values, num, size));
}

t_fdf			*check_valid_file(int fd)
{
	char	*line;
	t_line	*line_struct_tmp;
	t_line	*line_struct;

	line = NULL;
	line_struct = (t_line*)ft_memalloc(sizeof(t_line));
	if (get_next_line(fd, &line) < 1)
		exit(EXIT_FAILURE);
	check_line_valid(line);
	line_struct_tmp = line_to_struct(line);
	line_struct = line_struct_tmp;
	free(line);
	while (get_next_line(fd, &line) == 1)
	{
		check_line_valid(line);
		line_struct_tmp->next = line_to_struct(line);
		line_struct_tmp = line_struct_tmp->next;
		free(line);
	}
	return (create_fdf(line_struct));
}
