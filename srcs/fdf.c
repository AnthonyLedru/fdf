/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:17:49 by aledru            #+#    #+#             */
/*   Updated: 2018/01/06 19:08:14 by aledru           ###   ########.fr       */
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
	t_line	*line;

	max_x = 0;
	max_y = 0;
	line = fdf->line;
	max_y = get_max_line_size(fdf);
	if (max_x > max_y)
		max_x = (WIN_WIDTH / max_x) / 2;
	else
		max_x = (WIN_WIDTH / max_y) / 2;
	max_y = max_x / 2;
	return (create_point(max_x, max_y));
}

t_fdf			*create_fdf(t_line *line, int ac, char **av)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->line = line;
	fdf->spaces = get_spaces(fdf);
	fdf->translation = create_point(0, get_max_line_size(fdf) * fdf->spaces->y);
	fdf->palette = create_palette(ac, av);
	return (fdf);
}
