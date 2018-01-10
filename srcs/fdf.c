/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:17:49 by aledru            #+#    #+#             */
/*   Updated: 2018/01/10 15:03:00 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_max_line_size(t_fdf *fdf)
{
	int		max_line_size;
	t_line	*line;

	line = fdf->line;
	max_line_size = 0;
	while (line)
	{
		if (line->size > max_line_size)
			max_line_size = line->size;
		line = line->next;
	}
	return (max_line_size);
}

static t_point	*get_spaces(t_fdf *fdf)
{
	int		max_x;
	int		max_y;
	int		max_line;

	max_x = 0;
	max_y = 0;
	max_line = get_max_line_size(fdf);
	max_x = (WIN_WIDTH / max_line) / 2;
	max_y = (WIN_WIDTH / max_line) / 4;
	return (create_point(max_x, max_y));
}

t_fdf			*create_fdf(t_line *line, int ac, char **av)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
		malloc_error();
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->line = line;
	fdf->spaces = get_spaces(fdf);
	fdf->translation = create_point(0, get_max_line_size(fdf) * fdf->spaces->y);
	fdf->palette = create_palette(ac, av);
	return (fdf);
}
