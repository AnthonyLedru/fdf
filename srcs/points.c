/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:16:10 by aledru            #+#    #+#             */
/*   Updated: 2018/01/10 14:42:47 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_points(t_fdf *fdf)
{
	int				i;
	t_line			*line;
	t_point			*pos;
	t_point			*pos2;

	pos = create_point(fdf->translation->x, fdf->translation->y);
	pos2 = create_point(pos->x, pos->y);
	line = fdf->line;
	while (line)
	{
		i = 0;
		while (i < line->size)
		{
			set_point(line->points[i], pos->x,
					pos->y - line->values[i]->height * 10);
			set_point(pos, pos->x + fdf->spaces->x, pos->y - fdf->spaces->y);
			i++;
		}
		set_point(pos2, pos2->x + fdf->spaces->x, pos2->y + fdf->spaces->y);
		set_point(pos, pos2->x, pos2->y);
		line = line->next;
	}
	ft_memdel((void**)&pos);
	ft_memdel((void**)&pos2);
}
