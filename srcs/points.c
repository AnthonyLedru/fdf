/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:16:10 by aledru            #+#    #+#             */
/*   Updated: 2018/01/08 20:17:42 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_points(t_fdf *fdf, t_point *pos, t_point *pos2)
{
	t_point			**points;
	int				i;
	t_line			*line;

	line = fdf->line;
	while (line)
	{
		i = 0;
		if (!(points = (t_point**)ft_memalloc(sizeof(t_point*)
									* get_max_line_size(fdf))))
			malloc_error();
		while (i < line->size)
		{
			points[i] = create_point(pos->x, pos->y -
					line->values[i]->height * 10);
			set_point(pos, pos->x + fdf->spaces->x, pos->y - fdf->spaces->y);
			i++;
		}
		set_point(pos2, pos2->x + fdf->spaces->x, pos2->y + fdf->spaces->y);
		set_point(pos, pos2->x, pos2->y);
		line->points = points;
		line = line->next;
	}
	free(pos2);
	free(pos);
}

void			set_points_setup(t_fdf *fdf)
{
	t_point	*pos;
	t_point	*pos2;

	pos = create_point(fdf->translation->x, fdf->translation->y);
	pos2 = create_point(pos->x, pos->y);
	set_points(fdf, pos, pos2);
}
