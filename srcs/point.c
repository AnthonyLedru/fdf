/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:19:25 by aledru            #+#    #+#             */
/*   Updated: 2018/01/05 18:49:37 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			*create_point(int x, int y)
{
	t_point	*point;

	point = (t_point*)ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

void			set_point(t_point **point, int x, int y)
{
	(*point)->x = x;
	(*point)->y = y;
}

static void		set_points(t_fdf *fdf, t_point *pos, t_point *pos_cpy)
{
	t_point			**points;
	int				i;
	t_line			*line;

	line = fdf->line;
	points = fdf->line->points;
	while (line)
	{
		i = 0;
		points = (t_point**)ft_memalloc(sizeof(t_point*)
									* get_max_line_size(fdf));
		while (i < line->size)
		{
			points[i] = create_point(pos->x, pos->y -
					line->values[i]->height * 10);
			set_point(&pos, pos->x + fdf->spaces->x, pos->y - fdf->spaces->y);
			i++;
		}
		set_point(&pos_cpy, pos_cpy->x += fdf->spaces->x,
					pos_cpy->y += fdf->spaces->y);
		set_point(&pos, pos_cpy->x, pos_cpy->y);
		line->points = points;
		line = line->next;
	}
}

void			set_points_setup(t_fdf *fdf)
{
	t_point	*pos;
	t_point	*pos_cpy;

	pos = create_point(0, get_max_line_size(fdf) * fdf->spaces->y);
	pos_cpy = create_point(pos->x, pos->y);
	set_points(fdf, pos, pos_cpy);
}

void			translate_points(t_fdf *fdf, int x_inc, int y_inc)
{
	int	i;
	t_line	*line;

	line = fdf->line;
	while (line->next)
	{
		i = 0;
		while (i < line->size - 1)
		{
			line->points[i]->x = line->points[i]->x + x_inc;
			line->points[i]->y += line->points[i]->y + y_inc;
			i++;
		}
		line = line->next;
	}
	printf("%d\n", x_inc);
	printf("%d\n", y_inc);
	mlx_destroy_image(fdf->mlx, fdf->img->img_ptr);
	fdf->img = create_img(mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT));
	set_points_setup(fdf);
	draw_points(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img_ptr, 0, 0);
}
