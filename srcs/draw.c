/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:12:13 by aledru            #+#    #+#             */
/*   Updated: 2017/12/19 12:28:46 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_segment(t_point *a, t_point *b, t_fdf *fdf, int color)
{
	int			err;
	int			err_cpy;
	t_segment	*segment;

	segment = create_segment(ft_abs(b->x - a->x), ft_abs(b->y - a->y),
								a->x < b->x ? 1 : -1, a->y < b->y ? 1 : -1);
	err = (segment->d->x > segment->d->y ?
			segment->d->x : (segment->d->y * -1)) / 2;
	err_cpy = err;
	while (a->x != b->x || a->y != b->y)
	{
		printf("%d\n", color);
		if (a->y * WIN_WIDTH + a->x <= WIN_WIDTH * WIN_HEIGHT
				&& a->y * WIN_WIDTH + a->x >= 0)
			fdf->img->data[a->y * WIN_WIDTH + a->x] = color;
		err_cpy = err;
		if (err_cpy > segment->d->x * -1)
		{
			err -= segment->d->y;
			a->x += segment->s->x;
		}
		if (err_cpy < segment->d->y)
		{
			err += segment->d->x;
			a->y += segment->s->y;
		}
	}
}

static void	draw(t_fdf *fdf, t_point *base, t_point *sp)
{
	t_point	*point_a;
	t_point	*point_b;
	t_point *point_c;
	t_line *line;
	int		i;

	line = fdf->line;
	point_a = create_point(base->x, base->y);
	point_b = create_point(base->x, base->y);
	while (line)
	{
		i = 0;
		while (i < line->size)
		{
			draw_segment(point_a, point_b, fdf, line->points[i]->color);
			point_c = create_point(point_a->x + sp->x , point_a->y + sp->y);
			if (line->next)
				draw_segment(point_a, point_c, fdf, line->points[i]->color);
			set_point(&point_a, point_b->x, point_b->y);
			set_point(&point_b, point_b->x + sp->x, point_b->y - sp->y -
					(line->points[i]->height * 50));
			i++;
		}
		set_point(&point_a, base->x += sp->x, base->y += sp->y);
		set_point(&point_b, base->x, base->y);
		line = line->next;
	}
}

void		draw_setup(t_fdf *fdf)
{
	t_point	*base;
	t_point *sp;
	t_line	*line;
	int		max_line_size;

	line = fdf->line;
	max_line_size = 1;
	while (line)
	{
		if (line->size > max_line_size)
			max_line_size = line->size;
		line = line->next;
	}
	base = create_point(0, max_line_size * fdf->spaces->y);
	sp = create_point(fdf->spaces->x, fdf->spaces->y);
	draw(fdf, base, sp);
}
