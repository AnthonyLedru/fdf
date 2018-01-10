/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:12:13 by aledru            #+#    #+#             */
/*   Updated: 2018/01/10 16:07:13 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_color_gradient(t_gradient *gradient)
{
	if (gradient->begin->decimal == gradient->end->decimal)
		return (gradient->begin->decimal);
	if (gradient->step >= 1)
		return (gradient->end->decimal);
	gradient->color->r = gradient->begin->r + (gradient->end->r -
			gradient->begin->r) * gradient->step;
	gradient->color->g = gradient->begin->g + (gradient->end->g -
			gradient->begin->g) * gradient->step;
	gradient->color->b = gradient->begin->b + (gradient->end->b -
			gradient->begin->b) * gradient->step;
	gradient->color->decimal = (gradient->color->r << 16) + (gradient->color->g
								<< 8) + (gradient->color->b);
	gradient->step += gradient->mix;
	return (gradient->color->decimal);
}

static void		get_err(int err_cpy, int *err, t_segment *seg, t_point *a)
{
	if (err_cpy > seg->d->x * -1)
	{
		*err -= seg->d->y;
		a->x += seg->s->x;
	}
	if (err_cpy < seg->d->y)
	{
		*err += seg->d->x;
		a->y += seg->s->y;
	}
}

int				get_nb_pixel(t_point *a, t_point *b)
{
	int			nb_pixel;
	int			err;
	int			err_cpy;
	t_segment	*seg;

	nb_pixel = 0;
	seg = create_segment(abs(b->x - a->x), abs(b->y - a->y),
			a->x < b->x ? 1 : -1, a->y < b->y ? 1 : -1);
	err = (seg->d->x > seg->d->y ? seg->d->x : (seg->d->y * -1)) / 2;
	while (a->x != b->x || a->y != b->y)
	{
		err_cpy = err;
		get_err(err_cpy, &err, seg, a);
		nb_pixel++;
	}
	free_segment(seg);
	return (nb_pixel);
}

static void		draw_segment(t_point *a, t_point *b, t_fdf *fdf,
		t_gradient *gradient)
{
	int			err;
	int			err_cpy;
	t_segment	*seg;

	seg = create_segment(abs(b->x - a->x), abs(b->y - a->y),
								a->x < b->x ? 1 : -1, a->y < b->y ? 1 : -1);
	err = (seg->d->x > seg->d->y ? seg->d->x : (seg->d->y * -1)) / 2;
	while (a->x != b->x || a->y != b->y)
	{
		if (a->y * WIN_WIDTH + a->x <= WIN_WIDTH * WIN_HEIGHT
				&& a->y * WIN_WIDTH + a->x >= 0)
			fdf->img->data[a->y * WIN_WIDTH + a->x] = gradient->color->decimal;
		gradient->color->decimal = get_color_gradient(gradient);
		err_cpy = err;
		get_err(err_cpy, &err, seg, a);
	}
	free_segment(seg);
	free_gradient(gradient);
}

void			draw_points(t_fdf *fdf, t_point *tmp)
{
	t_line		*l;
	int			i;

	l = fdf->line;
	while (l)
	{
		i = -1;
		while (++i < l->size)
		{
			set_point(tmp, l->points[i]->x, l->points[i]->y);
			if (i < l->size - 1)
				draw_segment(l->points[i], l->points[i + 1], fdf,
					create_gradient(get_color(fdf, l->values[i]->height),
									get_color(fdf, l->values[i + 1]->height),
									l->points[i], l->points[i + 1]));
			set_point(l->points[i], tmp->x, tmp->y);
			if (l->next)
				draw_segment(l->points[i], l->next->points[i], fdf,
					create_gradient(get_color(fdf, l->values[i]->height),
									get_color(fdf, l->next->values[i]->height),
										l->points[i], l->next->points[i]));
		}
		l = l->next;
	}
	ft_memdel((void**)&tmp);
}
