/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:12:13 by aledru            #+#    #+#             */
/*   Updated: 2018/01/05 16:58:48 by aledru           ###   ########.fr       */
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
	gradient->color->decimal = rgb_to_decimal(gradient->color);
	gradient->step += gradient->mix;
	return (gradient->color->decimal);
}

static int		get_nb_pixel(t_point *a, t_point *b)
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
		nb_pixel++;
	}
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

static t_color	*get_color(t_fdf *fdf, int n)
{
	t_palette *palette;

	palette = fdf->palette;
	if (n <= 0)
		if (palette->c1)
			return (palette->c1);
	if (n >= 10 && n < 100)
		if (palette->c2)
			return (palette->c2);
	if (n >= 100 && n < 200)
		if (palette->c3)
			return (palette->c3);
	if (n >= 200 && n < 300)
		if (palette->c4)
			return (palette->c4);
	if (n >= 300)
		if (palette->c5)
			return (palette->c5);
	return (create_color(0xFFFFFF));
}

void			draw_points(t_fdf *fdf)
{
	t_line		*l;
	int			i;

	l = fdf->line;
	while (l->next)
	{
		i = 0;
		while (i < l->size - 1)
		{
			draw_segment(l->points[i], l->points[i + 1], fdf,
				create_gradient(get_color(fdf, l->values[i]->height),
				get_color(fdf, l->values[i + 1]->height),
				get_nb_pixel(create_point(l->points[i]->x, l->points[i]->y),
				create_point(l->points[i + 1]->x, l->points[i + 1]->y))));
			if (l->next)
				draw_segment(l->points[i], l->next->points[i + 1], fdf,
					create_gradient(get_color(fdf, l->values[i + 1]->height),
					get_color(fdf, l->next->values[i + 1]->height),
					get_nb_pixel(create_point(l->points[i]->x, l->points[i]->y),
					create_point(l->next->points[i + 1]->x,
					l->next->points[i + 1]->y))));
			i++;
		}
		l = l->next;
	}
}
