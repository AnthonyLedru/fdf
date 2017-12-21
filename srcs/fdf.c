/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:17:49 by aledru            #+#    #+#             */
/*   Updated: 2017/12/21 13:49:45 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_number_of_line(t_fdf *fdf)
{
	int		i;
	t_line	*line;

	i = 0;
	line = fdf->line;
	while (line->next)
	{
		line = line->next;
		i++;
	}
	return (i);
}

int			get_max_line_size(t_fdf *fdf)
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

t_point		*get_spaces(t_fdf *fdf)
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

t_fdf		*create_fdf(t_line *line)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->line = line;
	fdf->spaces = get_spaces(fdf);
	return (fdf);
}
