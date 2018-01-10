/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:46:57 by aledru            #+#    #+#             */
/*   Updated: 2018/01/10 13:05:08 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line			*create_line(t_line_values **values, int num, int size)
{
	t_line	*line;
	int		i;

	i = 0;
	if (!(line = (t_line*)ft_memalloc(sizeof(t_line))))
		malloc_error();
	line->values = values;
	if (!(line->points = (t_point**)ft_memalloc(sizeof(t_point*) * size)))
		malloc_error();
	while (i < size)
	{
		line->points[i] = create_point(0, 0);
		i++;
	}
	line->num = num;
	line->size = size;
	line->next = NULL;
	return (line);
}

t_line_values	*create_line_values(int height, t_color *color)
{
	t_line_values *line_values;

	if (!(line_values = (t_line_values*)ft_memalloc(sizeof(t_line_values))))
		malloc_error();
	line_values->height = height;
	line_values->color = color;
	return (line_values);
}
