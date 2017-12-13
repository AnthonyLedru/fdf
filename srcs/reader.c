/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:07:00 by aledru            #+#    #+#             */
/*   Updated: 2017/12/13 22:29:32 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		check_hexa(char	*line)
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
	while (*line && i < 6)
	{
		if (*line < 'A' || *line > 'Z')
			exit(EXIT_FAILURE);
		line++;
		i++;
	}
	if (i != 6)
		exit(EXIT_FAILURE);
}

static void		check_line_valid(int fd, char *line)
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
		{
			check_hexa(&(*line));
			line += 9;
		}
		if (*line == '\0')
			break ;
		if (*line && *line != ' ')
		{
			exit(EXIT_FAILURE);
		}
		while (*line && *line == ' ')
			line++;
	}
}

t_line			*line_to_struct(char *line)
{
	t_line			*line_struct;
	static int		num;
	char			**all_point;
	t_line_points	**points;
	int				size;

	all_point = ft_strsplit(line, ' ');
	size = 0;
	while (all_point[size])
		size++;
	points = (t_line_points**)ft_memalloc(sizeof(t_line_points*) * size);
	while (size - 1 >= 0)
	{
		points[size - 1] = create_line_points(ft_atoi(all_point[size - 1]), 0);
		size--;
	}
	while (all_point[size])
		size++;
	line_struct = create_line(points, num, size);
	num++;
	return (line_struct);
}

void			check_valid_file(int fd)
{
	char	*line;
	t_line	*line_struct_tmp;
	t_line	*line_struct;

	line = NULL;
	line_struct = (t_line*)ft_memalloc(sizeof(t_line));
	if (get_next_line(fd, &line) < 1)
		exit(EXIT_FAILURE);
	check_line_valid(fd, line);
	line_struct_tmp = line_to_struct(line);
	line_struct = line_struct_tmp;
	free(line);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		check_line_valid(fd, line);
		line_struct_tmp->next = line_to_struct(line);
		line_struct_tmp = line_struct_tmp->next;
		free(line);
	}
	printf("%s\n", "OK");
}
