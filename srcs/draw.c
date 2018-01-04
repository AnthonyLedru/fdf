/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:12:13 by aledru            #+#    #+#             */
/*   Updated: 2018/01/04 18:53:11 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_color_gradient(t_gradient *gradient)
{
	if (gradient->begin->decimal == gradient->end->decimal)
		return (gradient->begin->decimal);
	if (gradient->step >= 1)
		return (gradient->end->decimal);
	gradient->color->r = gradient->begin->r * (1.0 - gradient->step)
							+ gradient->end->r * (gradient->step);
	gradient->color->g =  gradient->begin->g * (1.0 - gradient->step)
							+ gradient->end->g * (gradient->step);
	gradient->color->b = gradient->begin->b * (1.0 - gradient->step)
							+ gradient->end->b * (gradient->step);
	gradient->color->decimal = rgb_to_decimal(gradient->color);
	gradient->step += gradient->mix;
	return (gradient->color->decimal);
}

static int		get_nb_pixel(t_point *a, t_point *b)
{
	int nb_pixel;
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

static void	draw_segment(t_point *a, t_point *b, t_fdf *fdf, t_gradient *gradient)
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

static t_color		*get_color(int n)
{
	if (n == 0)
	{
		return (create_color(0x0000FF));
	}
	if (n > 0)
		return (create_color(0xFF0000));
	return (create_color(0x000000));
}

void		draw_points(t_fdf *fdf)
{
	t_line	*line;
	int		i;
	t_gradient	*gradient;
	t_point		*cp1;
	t_point		*cp2;

	line = fdf->line;
	while (line->next)
	{
		i = 0;
		while (i < line->size - 1)
		{
			cp1 = create_point(line->points[i]->x, line->points[i]->y);
			cp2 = create_point(line->points[i + 1]->x, line->points[i + 1]->y);
			gradient = create_gradient(get_color(line->values[i]->height),
						get_color(line->values[i + 1]->height),
						get_nb_pixel(cp1, cp2));
			draw_segment(line->points[i], line->points[i + 1], fdf, gradient);
			if (line->next)
			{
				cp1 = create_point(line->points[i]->x, line->points[i]->y);
				cp2 = create_point(line->next->points[i + 1]->x,
									line->next->points[i + 1]->y);
				gradient = create_gradient(get_color(line->values[i + 1]->height),
						get_color(line->next->values[i + 1]->height),
						get_nb_pixel(cp1, cp2));
				draw_segment(line->points[i], line->next->points[i + 1], fdf,
						gradient);
			}
			i++;
		}
		line = line->next;
	}
}
