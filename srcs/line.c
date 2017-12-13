/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:46:57 by aledru            #+#    #+#             */
/*   Updated: 2017/12/13 16:43:52 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_line			*create_line(t_line_points **points, int num, int size)
{
	t_line *line;

	line = (t_line*)ft_memalloc(sizeof(t_line));
	line->points = points;
	line->num = num;
	line->size = size;
	line->next = NULL;
	return (line);
}

t_line_points	*create_line_points(int height, int color)
{
	t_line_points *line_points;

	line_points = (t_line_points*)ft_memalloc(sizeof(t_line_points));
	line_points->height = height;
	line_points->color = color;
	return (line_points);
}
