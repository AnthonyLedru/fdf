/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:46:57 by aledru            #+#    #+#             */
/*   Updated: 2017/12/20 18:36:17 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line			*create_line(t_line_values **points, int num, int size)
{
	t_line *line;

	line = (t_line*)ft_memalloc(sizeof(t_line));
	line->values = points;
	line->points = NULL;
	line->num = num;
	line->size = size;
	line->next = NULL;
	return (line);
}

t_line_values	*create_line_values(int height, int color)
{
	t_line_values *line_values;

	line_values = (t_line_values*)ft_memalloc(sizeof(t_line_values));
	line_values->height = height;
	line_values->color = color;
	return (line_values);
}
