/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:12:13 by aledru            #+#    #+#             */
/*   Updated: 2017/12/20 19:29:46 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_segment(t_point *a, t_point *b, t_fdf *fdf, int color)
{
	int			err;
	int			err_cpy;
	t_segment	*seg;

	seg = create_segment(ft_abs(b->x - a->x), ft_abs(b->y - a->y),
								a->x < b->x ? 1 : -1, a->y < b->y ? 1 : -1);
	err = (seg->d->x > seg->d->y ? seg->d->x : (seg->d->y * -1)) / 2;
	err_cpy = err;
	while (a->x != b->x || a->y != b->y)
	{
		if (a->y * WIN_WIDTH + a->x <= WIN_WIDTH * WIN_HEIGHT
				&& a->y * WIN_WIDTH + a->x >= 0)
			fdf->img->data[a->y * WIN_WIDTH + a->x] = color;
		err_cpy = err;
		if (err_cpy > seg->d->x * -1)
		{
			err -= seg->d->y;
			a->x += seg->s->x;
		}
		if (err_cpy < seg->d->y)
		{
			err += seg->d->x;
			a->y += seg->s->y;
		}
	}
}

void		draw_points(t_fdf *fdf)
{
	t_line	*line;
	int		i;

	line = fdf->line;
	while (line->next)
	{
		i = 0;
		while (i < line->size - 1)
		{
			draw_segment(line->points[i], line->points[i + 1],
					fdf, line->values[i]->color);
			if (line->next)
				draw_segment(line->points[i], line->next->points[i + 1],
					fdf, line->values[i]->color);
			i++;
		}
		line = line->next;
	}
}
